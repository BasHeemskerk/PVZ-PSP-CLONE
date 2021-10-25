#include "global.hpp"

#include "audioController.hpp"
#include "imageLoader.hpp"
#include "menu.hpp"
#include "gameStateChecker.hpp"
#include "about.hpp"
#include "more.hpp"
#include "almanac.hpp"
#include "settings.hpp"
#include "load.hpp"
#include "saveGame.hpp"
#include "level.hpp"


using namespace std;

#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)
#define PIXEL_SIZE (4) 
#define FRAME_SIZE (BUF_WIDTH * SCR_HEIGHT * PIXEL_SIZE)
#define ZBUF_SIZE (BUF_WIDTH SCR_HEIGHT * 2)

PSP_MODULE_INFO("Plants vs. Zombies", 0, 1, 0);

PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

#if _PSP_FW_VERSION >= 200
PSP_HEAP_SIZE_KB(20480);
#endif

static unsigned int __attribute__((aligned(16))) DisplayList[262144];

int exit_callback(int arg1, int arg2, void* common){
    sceKernelExitGame();
    return 0;
}

int callbackThread(SceSize args, void* argp){
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}

void setupCallbacks(){
    int thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, NULL);
    if (thid >= 0){
        sceKernelStartThread(thid, 0, NULL);
    }
}

void* fbp0 = NULL;
void* fbp1 = NULL;
void* renderTarget = NULL;
void* zbp = NULL;

void InitGU(){    
    fbp0 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    fbp1 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    zbp = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_4444);

    renderTarget = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);

    sceGuInit();
    sceGuStart(GU_DIRECT,DisplayList);

    sceGuDrawBuffer(GU_PSM_8888,fbp0,BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH,SCR_HEIGHT,fbp1,BUF_WIDTH);
    sceGuDepthBuffer(zbp,BUF_WIDTH);

    sceGuDepthRange(65535,0);
    sceGuDepthMask(GU_FALSE);

    sceGuOffset(2048 - (SCR_WIDTH / 2),2048 - (SCR_HEIGHT / 2));

    sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);

    sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

    sceGuScissor(0,0,SCR_WIDTH,SCR_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);

    sceGuAlphaFunc(GU_GREATER,0,0xff);
    sceGuEnable(GU_ALPHA_TEST);

    sceGuDepthFunc(GU_GEQUAL);
    sceGuEnable(GU_DEPTH_TEST);

    sceGuFrontFace(GU_CW);

    sceGuTexMode(GU_PSM_5650,0,0,0); 
    sceGuTexFunc(GU_TFX_REPLACE,GU_TCC_RGBA);
    sceGuTexFilter(GU_NEAREST,GU_NEAREST);

    sceGuEnable(GU_CULL_FACE);
    
    sceGuEnable(GU_TEXTURE_2D);

    sceGuEnable(GU_DITHER);

    sceGuEnable(GU_CLIP_PLANES);
    
    sceGuEnable(GU_LIGHTING);
    sceGuEnable(GU_LIGHT0);
    sceGuEnable(GU_LIGHT1);
    sceGuEnable(GU_LIGHT2);
    sceGuEnable(GU_LIGHT3);
    
    sceGuEnable(GU_FOG);

    sceGuEnable(GU_BLEND);
    sceGuBlendFunc(GU_ADD,GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA,0,0);

    sceGuShadeModel(GU_SMOOTH); 

    sceGuFinish();

    sceGuSync(0,0);

    sceDisplayWaitVblankStart();

    sceGuDisplay(GU_TRUE);
}

void initEngine(){
    setupCallbacks();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    InitGU();

    VirtualFileInit();
    oslInitAudio();
}

void gameStart(){
    imageControl::loadLoadingScreen();
    spriteControl::loadGrassLine();
    spriteControl::loadGrassBall();

    spriteControl::loadNumbers();

    audioControll::loadMenuMusic();
    audioControll::playMenuMusic();

    save::makeFile();
    save::openFile();


    //testing purposes!

    //audioControll::loadMinigameMusic();
    //audioControll::playMinigameMusic();
    //infoAlmanac::loadPlantInfoFiles();
}


auto main() -> int{

    
    SceCtrlData ctrlData;

    initEngine();
    gameStart();

    float buttonCountdown = 10;
    
    while(true){

        sceCtrlReadBufferPositive(&ctrlData, 1);

        sceDisplayWaitVblankStart();

        //running = isRunning();

        sceGuStart(GU_DIRECT,DisplayList);

        // clear screen

        sceGuClearColor(0x000000);
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

        // setup aspect ratio

        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(70.0f,16.0f/9.0f,0.5f,1000.0f);
            
        // setup camera
        sceGumMatrixMode(GU_VIEW);
        {
            ScePspFVector3 pos = {0, 0, 0};
            ScePspFVector3 rot = { 0, 0, 0 };

            sceGumLoadIdentity();
            sceGumTranslate(&pos);
            sceGumRotateXYZ(&rot);
        }

        if (state::loading){
            mainMenu::renderLoading();
            gameLoader::renderGrassLine();
            gameLoader::renderGrassBall();

            if (ctrlData.Buttons & PSP_CTRL_CROSS){
                state::loading = false;
                imageControl::unloadLoadingScreen();
                spriteControl::unloadGrassLine();
                spriteControl::unloadGrassBall();

                imageControl::loadMenuScreen();
                imageControl::loadCursor();
                state::menu = true;
            }
        }
        
        if (state::menu){
            mainMenu::renderTitle();
            mainMenu::renderNumbers();

            if (state::settings == false){
                mainMenu::renderCursor();
            }

            if (buttonCountdown <= 0){
                if (state::settings == false){
                    if (ctrlData.Buttons & PSP_CTRL_UP){
                        mainMenu::cursorPos -= 1;

                        buttonCountdown = 10;
                    }
                    else if (ctrlData.Buttons & PSP_CTRL_DOWN){
                        mainMenu::cursorPos += 1;

                        buttonCountdown = 10;
                    }

                    if (ctrlData.Buttons & PSP_CTRL_CROSS){
                        if (mainMenu::cursorPos == 0){
                            state::menu = false;
                            //imageControl::loadGarden();

                            if (level::wichWorld == 1){
                                audioControll::loadDayMusic();
                                audioControll::playDayMusic();
                            }
                            else if (level::wichWorld == 2){
                                audioControll::loadNightMusic();
                                audioControll::playNightMusic();
                            }
                            else if (level::wichWorld == 3){
                                audioControll::loadYardDayMusic();
                                audioControll::playYardDayMusic();
                            }
                            else if (level::wichWorld == 4){
                                audioControll::loadYardFogMusic();
                                audioControll::playYardFogMusic();
                            }
                            else if (level::wichWorld == 5){
                                audioControll::loadRoofMusic();
                                audioControll::playRoofMusic();
                            }
                            else if (level::wichWorld == 6){
                                audioControll::loadBossMusic();
                                audioControll::playBossMusic();
                            }

                            level::loadLevel();
                            level::loadSoll();
                            imageControl::loadScreenEdheUi();
                            level::loadStillZombies();

                            state::game = true;
                        }
                        else if (mainMenu::cursorPos == 1){
                            imageControl::loadSettingsBg();
                            spriteControl::loadOptionSlider();
                            spriteControl::loadOptionKnob();
                            state::settings = true;
                        }
                        else if (mainMenu::cursorPos == 2){
                            state::menu = false;
                            imageControl::unloadMenuScreen();
                            imageControl::unloadCursor();
                            audioControll::unloadMenuMusic();

                            imageControl::loadAlmanac();
                            imageControl::loadAlmanacCursor();

                            spriteControl::loadSunflowerSprites();
                            spriteControl::loadZombieStillSprites();

                            audioControll::loadStartMusic();
                            audioControll::playStartMusic();
                            infoAlmanac::loadPlantInfoFiles();

                            state::almanac = true;
                        }
                        else if (mainMenu::cursorPos == 3){
                            state::menu = false;
                            imageControl::unloadMenuScreen();
                            imageControl::unloadCursor();

                            imageControl::loadMoreGames();
                            state::more = true;
                        }
                        else if (mainMenu::cursorPos == 4){
                            state::menu = false;
                            imageControl::unloadMenuScreen();
                            imageControl::unloadCursor();

                            imageControl::loadAboutPage();
                            state::about = true;
                        }

                        buttonCountdown = 10;
                    }

                    if (mainMenu::cursorPos <= 0){
                        mainMenu::cursorPos = 0;
                    }

                    if (mainMenu::cursorPos >= 4){
                        mainMenu::cursorPos = 4;
                    }
                }
            }
            else{
                buttonCountdown -= 1;
            }
        }

        if (state::about){
            aboutRend::renderAbout();

            if (ctrlData.Buttons & PSP_CTRL_CIRCLE){
                state::about = false;
                imageControl::unloadAboutPage();

                imageControl::loadMenuScreen();
                imageControl::loadCursor();
                state::menu = true;
            }
        }

        if (state::more){
            moreRend::renderMoreGames();

            if (ctrlData.Buttons & PSP_CTRL_CIRCLE){
                state::more = false;
                imageControl::unloadMoreGames();

                imageControl::loadMenuScreen();
                imageControl::loadCursor();
                state::menu = true;
            }
        }

        if (state::almanac){
            infoAlmanac::renderMainAlmanac();
            if (infoAlmanac::almanacPage == 0){
                infoAlmanac::renderCursor();
                infoAlmanac::renderSunflower();
                infoAlmanac::renderZombie();
            }
            //infoAlmanac::fpsCounter();

            if (buttonCountdown <= 0){
                if (ctrlData.Buttons & PSP_CTRL_LEFT){
                    infoAlmanac::cursorPos -= 1;

                    buttonCountdown = 10;
                }
                else if (ctrlData.Buttons & PSP_CTRL_RIGHT){
                    infoAlmanac::cursorPos += 1;
                    
                    buttonCountdown = 10;
                }

                if (ctrlData.Buttons & PSP_CTRL_CIRCLE){
                    if (infoAlmanac::almanacPage == 0){
                        state::almanac = false;
                        imageControl::unloadAlmanac();

                        spriteControl::unloadSunFlowerSprites();
                        spriteControl::unloadZombieStillSprites();

                        infoAlmanac::unloadPlantInfoFiles();
                        audioControll::unloadStartMusic();

                        imageControl::loadMenuScreen();
                        imageControl::loadCursor();
                        audioControll::loadMenuMusic();
                        audioControll::playMenuMusic();
                        state::menu = true;

                        buttonCountdown = 10;
                    }
                    else if (infoAlmanac::almanacPage > 0){
                        spriteControl::loadSunflowerSprites();
                        spriteControl::loadZombieStillSprites();

                        infoAlmanac::almanacPage = 0;
                    }
                }

                if (ctrlData.Buttons & PSP_CTRL_CROSS){
                    if (infoAlmanac::cursorPos == 0){
                        infoAlmanac::almanacPage = 1;

                        spriteControl::unloadSunFlowerSprites();
                        spriteControl::unloadZombieStillSprites();
                    }
                    else if (infoAlmanac::cursorPos == 1){
                        infoAlmanac::almanacPage = 2;

                        spriteControl::unloadSunFlowerSprites();
                        spriteControl::unloadZombieStillSprites();
                    }

                    buttonCountdown = 10;
                }
            }
            else{
                buttonCountdown -= 1;
            }

            if (infoAlmanac::cursorPos <= 0){
                infoAlmanac::cursorPos = 0;
            }
            if (infoAlmanac::cursorPos >= 1){
                infoAlmanac::cursorPos = 1;
            }
        }

        if (state::settings){
            settingsMenu::renderSettingsMenu();
            settingsMenu::renderSlider();
            settingsMenu::renderKnob();

            if (ctrlData.Buttons & PSP_CTRL_UP){
                settingsMenu::cursorPos -= 1;
            }
            else if (ctrlData.Buttons & PSP_CTRL_DOWN){
                settingsMenu::cursorPos += 1;
            }

            if (ctrlData.Buttons & PSP_CTRL_LEFT){
                if (settingsMenu::cursorPos == 0){
                    settingsMenu::musicVolume -= 1;
                }
                else if (settingsMenu::cursorPos == 1){
                    settingsMenu::sfxVolume -= 1;
                }
            }
            else if (ctrlData.Buttons & PSP_CTRL_RIGHT){
                if (settingsMenu::cursorPos == 0){
                    settingsMenu::musicVolume += 1;
                }
                else if (settingsMenu::cursorPos == 1){
                    settingsMenu::sfxVolume += 1;
                }
            }

            if (ctrlData.Buttons & PSP_CTRL_CIRCLE){
                state::settings = false;
                imageControl::unloadSettingsBg();
                spriteControl::unloadOptionSlider();
                spriteControl::unloadOptionKnob();

                //save::deleteOldSaveConfig();
                //save::openFile();
                save::saveConfig();
            }


            if (settingsMenu::cursorPos <= 0){
                settingsMenu::cursorPos = 0;
            }

            if (settingsMenu::cursorPos >= 1){
                settingsMenu::cursorPos = 1;
            }

            if (settingsMenu::musicVolume <= 0){
                settingsMenu::musicVolume = 0;
            }
            else if (settingsMenu::musicVolume >= 100){
                settingsMenu::musicVolume = 100;
            }

            if (settingsMenu::sfxVolume <= 0){
                settingsMenu::sfxVolume = 0;
            }
            else if (settingsMenu::sfxVolume >= 100){
                settingsMenu::sfxVolume = 100;
            }
        }

        if (state::game){
            level::renderLevel();
            level::renderSoll();
            level::renderScreenEdge();
            level::renderZombiesStill();
        }

        state::checkbool();
        
            
        sceGuFinish();
        sceGuSync(0,0);

        sceGuSwapBuffers();
    }
}