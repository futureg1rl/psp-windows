/* To compile you must use a dos compiler, preferebly Turbo C 1.1
   Compile DBS.cpp
   Do not edit anything, if you find bugs report them to me

TODO:
-Fix/aline all menus (Help menus, Dsbxc menus, Utility menus)
-Add default to every switch
-Finish "Excute DOS command"
-Finish "Change screen and txt color"
-Finish "Open file editor"
-Finish adding all the stuff in Keyhelp
-Add more things to Troubleshooting
-Finish Dsbxc stuff
-rearange the mainmenu and utility menu stuff
-MORE...


                                                       Gaby_64 */

#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <process.h> // for system("command"); //
#include <dos.h>  // for delay(milsec); //
#include <graphics.h>
#define ESC 27

int input;
char dbvdbsvlm[80]="      verdosbox=0.71     ver of dbs=2,C085     lastmodafied=2008-02-29      ";

//---------------------------------Graphic functions--------------------------------------//

  int bkgcol=4;
  int txtcol=6;
  char setcol[50]="echo [1;36;44m[J";
  int xasp, yasp;
  int    GraphDriver;
  int    GraphMode;
  double AspectRatio;
  int    MaxX, MaxY;
  int    MaxColors;
  int    ErrorCode;
  struct palettetype palette;
  void Initialize()
{
  GraphDriver = DETECT;
  initgraph( &GraphDriver, &GraphMode, "" );
  ErrorCode = graphresult();
  if( ErrorCode != grOk )
  {
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }
  getpalette( &palette );
  MaxColors = getmaxcolor() + 1;
  MaxX = getmaxx();
  MaxY = getmaxy();
  getaspectratio( &xasp, &yasp );
  AspectRatio = (double)xasp / (double)yasp;
}
void SetMCGA()
{
  _AX = 0x0013;
  geninterrupt (0x10);
}
void SetText()
{
  _AX = 0x0003;
  geninterrupt (0x10);
}
void GetPal(unsigned char ColorNo, unsigned char &R, unsigned char &G, unsigned char &B)
{
  outp (0x03C7,ColorNo);
  R = inp (0x03C9);
  G = inp (0x03C9);
  B = inp (0x03C9);
}
void Pal(unsigned char ColorNo, unsigned char R, unsigned char G, unsigned char B)
{
  outp (0x03C8,ColorNo);
  outp (0x03C9,R);
  outp (0x03C9,G);
  outp (0x03C9,B);
}
void FadeDown()
{
unsigned char Tmp[3];
  for(int loop1=0; loop1<64; loop1++) {
    delay(10);
    for(int loop2=0; loop2<256; loop2++) {
      GetPal(loop2,Tmp[0],Tmp[1],Tmp[2]);
      if (Tmp[0] > 0) Tmp[0]--;
      if (Tmp[1] > 0) Tmp[1]--;
      if (Tmp[2] > 0) Tmp[2]--;
      Pal(loop2,Tmp[0],Tmp[1],Tmp[2]);
    }
  }
  system("cls");
  system(setcol);
}
void clstocol()
{
  system("cls");
  system(setcol);
}
//---------------------------------------DBS Functions--------------------------------------------------------------------//

char dsbxcp[20];
char dsbxcv[20];
char setdsbxc[20];
char dsbxt[20];
char dsbxcc1[20];
char dsbxcc2[20];
char dsbxcc3[20];
char dsbxcc4[20];
char dsbxcc5[20];
char dsbxcc6[20];
char dsbxcc7[20];
char dsbxcc8[20];
char dsbxcc9[20];
char dsbxcc10[20];
char dsbxcc11[20];

void dsbxs()
{
                FadeDown();
                cout<<"\n";
                cout<<"                                  "<<dsbxt<<"\n";
                cout<<"\n";
                cout<<"       ___________________________________________________________________\n";
                cout<<"      |"<<  dsbxcc1 <<"|"<<  dsbxcc2 <<"|"<<  dsbxcc3 <<"|"<<  dsbxcc4 <<"|\n";
                cout<<"      |________________|________________|________________|________________|\n";
                cout<<"      |"<<  dsbxcc5 <<"|"<<  dsbxcc6 <<"|"<<  dsbxcc7 <<"|"<<  dsbxcc8 <<"|\n";
                cout<<"      |________________|________________|________________|________________|\n";
                cout<<"      |"<<  dsbxcc9 <<"|"<< dsbxcc10 <<"|"<< dsbxcc11 <<"|                |\n";
                cout<<"      |________________|________________|________________|________________|\n";
                cout<<"\n";
                cout << "Enter the property you want to edit: ";
                cin >> dsbxcp;
                cout << "Enter the value you want to set to "<<dsbxcp<<"= ";
                cin >> dsbxcv;
                sprintf(setdsbxc, "%s=%s", dsbxcp, dsbxcv);
                printf("You have set %s to %s", dsbxcp, dsbxcv, "" );
                system(setdsbxc);
                input=getch();
                if ( input == ESC )
                {
                   system("echo [1;37;40m");
                   SetText();
                   exit(1);
                }
}

void dsbxc()
{
  dsbxcmenu:
  int input;
  FadeDown();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                           #######################                         บ\n";
  cout<<" ?                           #    DBS DSBX MENU    #                         บ\n";
  cout<<" ?                           #######################                         บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                       Û฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿?                    บ\n";
  cout<<" ?                       ?q. Back to the main menu    ?                    บ\n";
  cout<<" ?                       ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ?                    บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?All settings you change in here are only temporary, when you restart       บ\n";
  cout<<" ?dosbox the settings from the dosbox.conf will be reloaded.                 บ\n";
  cout<<" ?   _____________________________________________________________________   บ\n";
  cout<<" ?  |    sdl=a    |   dosbox=b  |   render=c  |    cpu=d    |   mixer=e   |  บ\n";
  cout<<" ?  |_____________|_____________|_____________|_____________|_____________|  บ\n";
  cout<<" ?  |    midi=f   |  sblaster=g |    gus=h    |  speaker=i  | joystick=j  |  บ\n";
  cout<<" ?  |_____________|_____________|_____________|_____________|_____________|  บ\n";
  cout<<" ?  |  serial=k   |    dos=l    |    ipx=m    |             |             |  บ\n";
  cout<<" ?  |_____________|_____________|_____________|_____________|_____________|  บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บSection:                                                                    บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  input=getch();
  if ( input == ESC )
  {
      system("echo [1;37;40m");
      SetText();
      exit(1);
  }
  switch ( input ) {
         case 97:
                sprintf(dsbxcc1, "   fullscreen   ");
                sprintf(dsbxcc2, "   fulldouble   ");
                sprintf(dsbxcc3, " fullresolution ");
                sprintf(dsbxcc4, "windowresolution");
                sprintf(dsbxcc5, "     output     ");
                sprintf(dsbxcc6, "    autolock    ");
                sprintf(dsbxcc7, "  sensitivity   ");
                sprintf(dsbxcc8, "  waitonerror   ");
                sprintf(dsbxcc9, "    priority    ");
                sprintf(dsbxcc10, "   mapperfile   ");
                sprintf(dsbxcc11, "  usescancodes  ");
                sprintf(dsbxt, "[SDL]");
                dsbxs();
                goto dsbxcmenu;
         case 98:


                sprintf(dsbxcc1, "    machine     ");
                sprintf(dsbxcc2, "    memsize     ");
                sprintf(dsbxcc3, "    captures    ");
                sprintf(dsbxcc4, "                ");
                sprintf(dsbxcc5, "                ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[DOSBOX]");
                dsbxs();
                goto dsbxcmenu;
         case 99:
                sprintf(dsbxcc1, "   frameskip    ");
                sprintf(dsbxcc2, "     aspect     ");
                sprintf(dsbxcc3, "     scaler     ");
                sprintf(dsbxcc4, "                ");
                sprintf(dsbxcc5, "                ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[RENDER]");
                dsbxs();
                goto dsbxcmenu;
         case 100:
                sprintf(dsbxcc1, "      core      ");
                sprintf(dsbxcc2, "     cycles     ");
                sprintf(dsbxcc3, "    cycleup     ");
                sprintf(dsbxcc4, "   cycledown    ");
                sprintf(dsbxcc5, "   autocycle    ");
                sprintf(dsbxcc6, "   mincycles    ");
                sprintf(dsbxcc7, "   maxcycles    ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[CPU]");
                dsbxs();
                goto dsbxcmenu;
         case 101:
                sprintf(dsbxcc1, "    nosound     ");
                sprintf(dsbxcc2, "     rate       ");
                sprintf(dsbxcc3, "   blocksize    ");
                sprintf(dsbxcc4, "   prebuffer    ");
                sprintf(dsbxcc5, "                ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[MIXER]");
                dsbxs();
                goto dsbxcmenu;
         case 102:
                sprintf(dsbxcc1, "     mpu401     ");
                sprintf(dsbxcc2, "     device     ");
                sprintf(dsbxcc3, "     config     ");
                sprintf(dsbxcc4, "                ");
                sprintf(dsbxcc5, "                ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[MIDI]");
                dsbxs();
                goto dsbxcmenu;
         case 103:
                sprintf(dsbxcc1, "     sbtype     ");
                sprintf(dsbxcc2, "     sbbase     ");
                sprintf(dsbxcc3, "      irq       ");
                sprintf(dsbxcc4, "      dma       ");
                sprintf(dsbxcc5, "      hdma      ");
                sprintf(dsbxcc6, "     mixer      ");
                sprintf(dsbxcc7, "    oplmode     ");
                sprintf(dsbxcc8, "    oplrate     ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[SBLASTER]");
                dsbxs();
                goto dsbxcmenu;
         case 104:
                sprintf(dsbxcc1, "      gus       ");
                sprintf(dsbxcc2, "    gusrate     ");
                sprintf(dsbxcc3, "    gusbase     ");
                sprintf(dsbxcc4, "     irq1       ");
                sprintf(dsbxcc5, "     irq2       ");
                sprintf(dsbxcc6, "     dma1       ");
                sprintf(dsbxcc7, "     dma2       ");
                sprintf(dsbxcc8, "   ultradir     ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[GUS]");
                dsbxs();
                goto dsbxcmenu;
         case 105:
                sprintf(dsbxcc1, "   pcspeaker    ");
                sprintf(dsbxcc2, "    pcrate      ");
                sprintf(dsbxcc3, "     tandy      ");
                sprintf(dsbxcc4, "   tandyrate    ");
                sprintf(dsbxcc5, "    disney      ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[SPEAKER]");
                dsbxs();
                goto dsbxcmenu;
         case 106:
                sprintf(dsbxcc1, "  joysticktype  ");
                sprintf(dsbxcc2, "     timed      ");
                sprintf(dsbxcc3, "    autofire    ");
                sprintf(dsbxcc4, "     swap34     ");
                sprintf(dsbxcc5, "   buttonwrap   ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[JOYSTICK]");
                dsbxs();
                goto dsbxcmenu;
         case 107:
                sprintf(dsbxcc1, "    serial1     ");
                sprintf(dsbxcc2, "    serial2     ");
                sprintf(dsbxcc3, "    serial3     ");
                sprintf(dsbxcc4, "    serial4     ");
                sprintf(dsbxcc5, "                ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[SERIAL]");
                dsbxs();
                goto dsbxcmenu;
         case 108:
                sprintf(dsbxcc1, "      xms       ");
                sprintf(dsbxcc2, "      ems       ");
                sprintf(dsbxcc3, "      umb       ");
                sprintf(dsbxcc4, "                ");
                sprintf(dsbxcc5, "                ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[DOS]");
                dsbxs();
                goto dsbxcmenu;
         case 109:
                sprintf(dsbxcc1, "      ipx       ");
                sprintf(dsbxcc2, "                ");
                sprintf(dsbxcc3, "                ");
                sprintf(dsbxcc4, "                ");
                sprintf(dsbxcc5, "                ");
                sprintf(dsbxcc6, "                ");
                sprintf(dsbxcc7, "                ");
                sprintf(dsbxcc8, "                ");
                sprintf(dsbxcc9, "                ");
                sprintf(dsbxcc10, "                ");
                sprintf(dsbxcc11, "                ");
                sprintf(dsbxt, "[IPX]");
                dsbxs();
                goto dsbxcmenu;
         case 113:
                goto end;
         default:
                FadeDown();
                cout<<"Error' you entered the wrong input\n";
                delay(1200);
                goto dsbxcmenu;
         }
end:;
}

void credits()
{
  FadeDown();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                          #      Credits        #                          บ\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บThanks to CrazyC and the dosbox team for this awsome dos emulator.          บ\n";
  cout<<" บAnd me Gaby_64 from BB for taking my own time to test and to make           บ\n";
  cout<<" บWindows98-95-3.1 work on dosbox and making it faster. I'd like to           บ\n";
  cout<<" บtanx also Sam Brown for the w3.1 img.                                       บ\n";
  cout<<" บIf you need any help or you want to help you can contact me by email        บ\n";
  cout<<" บat Gaby_64@live.ca or you can find me on BB.                                บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บDISCLAMER:                                                                  บ\n";
  cout<<" บSorry I have to put this but appearently some people like to post stuff thatบ\n";
  cout<<" บthey did not do and get credit for it!!!!                                   บ\n";
  cout<<" บYour are not permeted to post this anywere onlese you ask me. You must      บ\n";
  cout<<" บalways include my name and a link to the source of your info wich is suposedบ\n";
  cout<<" บto be DJKMan.freesmfhosting.com . Always keep DBS in its original zip file  บ\n";
  cout<<" บwhen given link. You are not alowed to share passowrd. For every update I   บ\n";
  cout<<" บwill be changing the password                                               บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
     SetText();
     exit(1);
  }
}
//--------------------------------------------------------Help Menu--------------------------------------------------------//
char khlp1[20];
char khlp2[20];
char khlp3[20];
char khlp4[20];
char khlp5[20];
char khlp6[20];
char khlp7[20];
char khlp8[20];
char khlp9[20];
char khlp10[20];
char khlp11[20];
char khlp12[20];
char khlp13[20];
char khlp14[20];
char khlp15[20];
char khlp16[20];
char khlp17[20];
char khlp18[20];
char khlp19[20];
char khlp20[20];
char khlp21[20];
char khlp22[20];
char khlp23[20];
char khlp24[20];
char khlp25[20];
char khlp26[20];
char khlp27[20];
char khlp28[20];
char khlp29[20];
char khlp30[20];
char khlp31[20];
char khlp32[20];
char khlp33[20];
char khlp34[20];
char khlp35[20];
char khlp36[20];
char khlp37[20];
char khlp38[20];
char khlp39[20];
char khlp40[20];
char khlp41[20];
char khlp42[20];
char khlp43[20];
char khlp44[20];

void khlp()
{
  FadeDown();
  cout<<"  |"<<khlp1<<"|"<<khlp2<<"|"<<khlp3<<"|"<<khlp4<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp5<<"|"<<khlp6<<"|"<<khlp7<<"|"<<khlp8<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp9<<"|"<<khlp10<<"|"<<khlp11<<"|"<<khlp12<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp13<<"|"<<khlp14<<"|"<<khlp15<<"|"<<khlp16<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp17<<"|"<<khlp18<<"|"<<khlp19<<"|"<<khlp20<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp21<<"|"<<khlp22<<"|"<<khlp23<<"|"<<khlp24<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp25<<"|"<<khlp26<<"|"<<khlp27<<"|"<<khlp28<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp29<<"|"<<khlp30<<"|"<<khlp31<<"|"<<khlp32<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp33<<"|"<<khlp34<<"|"<<khlp35<<"|"<<khlp36<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp37<<"|"<<khlp38<<"|"<<khlp39<<"|"<<khlp40<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"  |"<<khlp41<<"|"<<khlp42<<"|"<<khlp43<<"|"<<khlp44<<"|\n";
  cout<<"  |__________________|__________________|__________________|__________________|\n";
  cout<<"Press any key to view the rest.\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
     SetText();
     exit(1);
  }
}



void helpmenu()
{
  helpmenu:
  FadeDown();

  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                          #    DBS HELP MENU    #                          บ\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                      Û฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿?                     บ\n";
  cout<<" ?                      ?1. Keyhelp                  ?                     บ\n";
  cout<<" ?                      ?2. Troubleshooting          ?                     บ\n";
  cout<<" ?                      ?3. Back to the main menu    ?                     บ\n";
  cout<<" ?                      ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ?                     บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บSelection:                                                                  บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
     SetText();
     exit(1);
  }
  switch ( input ) {
         case 49:
                keyhelp:
                FadeDown();
                cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
                cout<<" ?                          #######################                          บ\n";
                cout<<" ?                          #  DBS KEYHELP MENU   #                          บ\n";
                cout<<" ?                          #######################                          บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?<<dbvdbsvlm<<"บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                      Û฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿?                     บ\n";
                cout<<" ?                      ?1. Section 1 (a,b,c,d,...)  ?                     บ\n";
                cout<<" ?                      ?2. Section 2 (f1,1,2,...)   ?                     บ\n";
                cout<<" ?                      ?3. Section 3 (Lalt,del,..)  ?                     บ\n";
                cout<<" ?                      ?4. Back to the helpmenu     ?                     บ\n";
                cout<<" ?                      ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ?                     บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" ?                                                                           บ\n";
                cout<<" บSelection:                                                                  บ\n";
                cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
                input=getch();
                if ( input == ESC )
                {
                   system("echo [1;37;40m");
                   SetText();
                   exit(1);
                }
                switch ( input ) {
                       case 49:
                              sprintf(khlp1, "  a = tri & cir   ");
                              sprintf(khlp2, "  b = lef & lef   ");
                              sprintf(khlp3, "  c = squ & cir   ");
                              sprintf(khlp4, "  d = rig & rig   ");
                              sprintf(khlp5, "  e = tri & tri   ");
                              sprintf(khlp6, "  f = up  & lef   ");
                              sprintf(khlp7, "  g = lef & rig   ");
                              sprintf(khlp8, "  h = cir & squ   ");
                              sprintf(khlp9, "  i = cir & cir   ");
                              sprintf(khlp10, "  j = rig & lef   ");
                              sprintf(khlp11, "  k = tri & lef   ");
                              sprintf(khlp12, "  l = rig & up    ");
                              sprintf(khlp13, "  m = rig & squ   ");
                              sprintf(khlp14, "  n = cir & tri   ");
                              sprintf(khlp15, "  o = up  & up    ");
                              sprintf(khlp16, "  p = squ & rig   ");
                              sprintf(khlp17, "  q = squ & up    ");
                              sprintf(khlp18, "  r = tri & squ   ");
                              sprintf(khlp19, "  s = squ & squ   ");
                              sprintf(khlp20, "  t = squ & tri   ");
                              sprintf(khlp21, "  u = up  & rig   ");
                              sprintf(khlp22, "  v = up  & tri   ");
                              sprintf(khlp23, "  w = tri & up    ");
                              sprintf(khlp24, "  x = up  & squ   ");
                              sprintf(khlp25, "  y = lef & up    ");
                              sprintf(khlp26, "  z = rig & tri   ");
                              sprintf(khlp27, "  [ = lef & squ   ");
                              sprintf(khlp28, "  ] = rig & cir   ");
                              sprintf(khlp29, "  / = cir & rig   ");
                              sprintf(khlp30, "  - = cir & up    ");
                              sprintf(khlp31, "  . = cir & lef   ");
                              sprintf(khlp32, "  \ = squ & lef   ");
                              sprintf(khlp33, "  ; = tri & up    ");
                              sprintf(khlp34, "  , = lef & cir   ");
                              sprintf(khlp35, "  ' = lef & tri   ");
                              sprintf(khlp36, "  ' = up  & cir   ");
                              sprintf(khlp37, ": = tri+ up  & lef");
                              sprintf(khlp38, "? = cir+ tri & rig");
                              sprintf(khlp39, "_ = cir+ tri & up ");
                              sprintf(khlp40, "} = cir+ tri & lef");
                              sprintf(khlp41, "~ =  up+ tri & cir");
                              sprintf(khlp42, "{ = lef+ up  & squ");
                              sprintf(khlp43, "  = lef+ up  & tri");
                              sprintf(khlp44, "< = lef+ up  & cir");
                              khlp();
                              sprintf(khlp1, "                  ");
                              sprintf(khlp2, "                  ");
                              sprintf(khlp3, "                  ");
                              sprintf(khlp4, "                  ");
                              sprintf(khlp5, "                  ");
                              sprintf(khlp6, "                  ");
                              sprintf(khlp7, "                  ");
                              sprintf(khlp8, "                  ");
                              sprintf(khlp9, "                  ");
                              sprintf(khlp10, "                  ");
                              sprintf(khlp11, "                  ");
                              sprintf(khlp12, "                  ");
                              sprintf(khlp13, "                  ");
                              sprintf(khlp14, "                  ");
                              sprintf(khlp15, "                  ");
                              sprintf(khlp16, "                  ");
                              sprintf(khlp17, "                  ");
                              sprintf(khlp18, "                  ");
                              sprintf(khlp19, "                  ");
                              sprintf(khlp20, "                  ");
                              sprintf(khlp21, "                  ");
                              sprintf(khlp22, "                  ");
                              sprintf(khlp23, "                  ");
                              sprintf(khlp24, "                  ");
                              sprintf(khlp25, "                  ");
                              sprintf(khlp26, "                  ");
                              sprintf(khlp27, "                  ");
                              sprintf(khlp28, "                  ");
                              sprintf(khlp29, "                  ");
                              sprintf(khlp30, "                  ");
                              sprintf(khlp31, "                  ");
                              sprintf(khlp32, "                  ");
                              sprintf(khlp33, "                  ");
                              sprintf(khlp34, "                  ");
                              sprintf(khlp35, "                  ");
                              sprintf(khlp36, "                  ");
                              sprintf(khlp37, "                  ");
                              sprintf(khlp38, "                  ");
                              sprintf(khlp39, "                  ");
                              sprintf(khlp40, "                  ");
                              sprintf(khlp41, "                  ");
                              sprintf(khlp42, "                  ");
                              sprintf(khlp43, "                  ");
                              sprintf(khlp44, "                  ");
                              khlp();
                              goto helpmenu;
                       case 50:
                              sprintf(khlp1, "                  ");
                              sprintf(khlp2, "                  ");
                              sprintf(khlp3, "                  ");
                              sprintf(khlp4, "                  ");
                              sprintf(khlp5, "                  ");
                              sprintf(khlp6, "                  ");
                              sprintf(khlp7, "                  ");
                              sprintf(khlp8, "                  ");
                              sprintf(khlp9, "                  ");
                              sprintf(khlp10, "                  ");
                              sprintf(khlp11, "                  ");
                              sprintf(khlp12, "                  ");
                              sprintf(khlp13, "                  ");
                              sprintf(khlp14, "                  ");
                              sprintf(khlp15, "                  ");
                              sprintf(khlp16, "                  ");
                              sprintf(khlp17, "                  ");
                              sprintf(khlp18, "                  ");
                              sprintf(khlp19, "                  ");
                              sprintf(khlp20, "                  ");
                              sprintf(khlp21, "                  ");
                              sprintf(khlp22, "                  ");
                              sprintf(khlp23, "                  ");
                              sprintf(khlp24, "                  ");
                              sprintf(khlp25, "                  ");
                              sprintf(khlp26, "                  ");
                              sprintf(khlp27, "                  ");
                              sprintf(khlp28, "                  ");
                              sprintf(khlp29, "                  ");
                              sprintf(khlp30, "                  ");
                              sprintf(khlp31, "                  ");
                              sprintf(khlp32, "                  ");
                              sprintf(khlp33, "                  ");
                              sprintf(khlp34, "                  ");
                              sprintf(khlp35, "                  ");
                              sprintf(khlp36, "                  ");
                              sprintf(khlp37, "                  ");
                              sprintf(khlp38, "                  ");
                              sprintf(khlp39, "                  ");
                              sprintf(khlp40, "                  ");
                              sprintf(khlp41, "                  ");
                              sprintf(khlp42, "                  ");
                              sprintf(khlp43, "                  ");
                              sprintf(khlp44, "                  ");
                              khlp();
                              sprintf(khlp1, "                  ");
                              sprintf(khlp2, "                  ");
                              sprintf(khlp3, "                  ");
                              sprintf(khlp4, "                  ");
                              sprintf(khlp5, "                  ");
                              sprintf(khlp6, "                  ");
                              sprintf(khlp7, "                  ");
                              sprintf(khlp8, "                  ");
                              sprintf(khlp9, "                  ");
                              sprintf(khlp10, "                  ");
                              sprintf(khlp11, "                  ");
                              sprintf(khlp12, "                  ");
                              sprintf(khlp13, "                  ");
                              sprintf(khlp14, "                  ");
                              sprintf(khlp15, "                  ");
                              sprintf(khlp16, "                  ");
                              sprintf(khlp17, "                  ");
                              sprintf(khlp18, "                  ");
                              sprintf(khlp19, "                  ");
                              sprintf(khlp20, "                  ");
                              sprintf(khlp21, "                  ");
                              sprintf(khlp22, "                  ");
                              sprintf(khlp23, "                  ");
                              sprintf(khlp24, "                  ");
                              sprintf(khlp25, "                  ");
                              sprintf(khlp26, "                  ");
                              sprintf(khlp27, "                  ");
                              sprintf(khlp28, "                  ");
                              sprintf(khlp29, "                  ");
                              sprintf(khlp30, "                  ");
                              sprintf(khlp31, "                  ");
                              sprintf(khlp32, "                  ");
                              sprintf(khlp33, "                  ");
                              sprintf(khlp34, "                  ");
                              sprintf(khlp35, "                  ");
                              sprintf(khlp36, "                  ");
                              sprintf(khlp37, "                  ");
                              sprintf(khlp38, "                  ");
                              sprintf(khlp39, "                  ");
                              sprintf(khlp40, "                  ");
                              sprintf(khlp41, "                  ");
                              sprintf(khlp42, "                  ");
                              sprintf(khlp43, "                  ");
                              sprintf(khlp44, "                  ");
                              khlp();
                              goto helpmenu;
                       case 51:
                              sprintf(khlp1, "                  ");
                              sprintf(khlp2, "                  ");
                              sprintf(khlp3, "                  ");
                              sprintf(khlp4, "                  ");
                              sprintf(khlp5, "                  ");
                              sprintf(khlp6, "                  ");
                              sprintf(khlp7, "                  ");
                              sprintf(khlp8, "                  ");
                              sprintf(khlp9, "                  ");
                              sprintf(khlp10, "                  ");
                              sprintf(khlp11, "                  ");
                              sprintf(khlp12, "                  ");
                              sprintf(khlp13, "                  ");
                              sprintf(khlp14, "                  ");
                              sprintf(khlp15, "                  ");
                              sprintf(khlp16, "                  ");
                              sprintf(khlp17, "                  ");
                              sprintf(khlp18, "                  ");
                              sprintf(khlp19, "                  ");
                              sprintf(khlp20, "                  ");
                              sprintf(khlp21, "                  ");
                              sprintf(khlp22, "                  ");
                              sprintf(khlp23, "                  ");
                              sprintf(khlp24, "                  ");
                              sprintf(khlp25, "                  ");
                              sprintf(khlp26, "                  ");
                              sprintf(khlp27, "                  ");
                              sprintf(khlp28, "                  ");
                              sprintf(khlp29, "                  ");
                              sprintf(khlp30, "                  ");
                              sprintf(khlp31, "                  ");
                              sprintf(khlp32, "                  ");
                              sprintf(khlp33, "                  ");
                              sprintf(khlp34, "                  ");
                              sprintf(khlp35, "                  ");
                              sprintf(khlp36, "                  ");
                              sprintf(khlp37, "                  ");
                              sprintf(khlp38, "                  ");
                              sprintf(khlp39, "                  ");
                              sprintf(khlp40, "                  ");
                              sprintf(khlp41, "                  ");
                              sprintf(khlp42, "                  ");
                              sprintf(khlp43, "                  ");
                              sprintf(khlp44, "                  ");
                              khlp();
                              sprintf(khlp1, "                  ");
                              sprintf(khlp2, "                  ");
                              sprintf(khlp3, "                  ");
                              sprintf(khlp4, "                  ");
                              sprintf(khlp5, "                  ");
                              sprintf(khlp6, "                  ");
                              sprintf(khlp7, "                  ");
                              sprintf(khlp8, "                  ");
                              sprintf(khlp9, "                  ");
                              sprintf(khlp10, "                  ");
                              sprintf(khlp11, "                  ");
                              sprintf(khlp12, "                  ");
                              sprintf(khlp13, "                  ");
                              sprintf(khlp14, "                  ");
                              sprintf(khlp15, "                  ");
                              sprintf(khlp16, "                  ");
                              sprintf(khlp17, "                  ");
                              sprintf(khlp18, "                  ");
                              sprintf(khlp19, "                  ");
                              sprintf(khlp20, "                  ");
                              sprintf(khlp21, "                  ");
                              sprintf(khlp22, "                  ");
                              sprintf(khlp23, "                  ");
                              sprintf(khlp24, "                  ");
                              sprintf(khlp25, "                  ");
                              sprintf(khlp26, "                  ");
                              sprintf(khlp27, "                  ");
                              sprintf(khlp28, "                  ");
                              sprintf(khlp29, "                  ");
                              sprintf(khlp30, "                  ");
                              sprintf(khlp31, "                  ");
                              sprintf(khlp32, "                  ");
                              sprintf(khlp33, "                  ");
                              sprintf(khlp34, "                  ");
                              sprintf(khlp35, "                  ");
                              sprintf(khlp36, "                  ");
                              sprintf(khlp37, "                  ");
                              sprintf(khlp38, "                  ");
                              sprintf(khlp39, "                  ");
                              sprintf(khlp40, "                  ");
                              sprintf(khlp41, "                  ");
                              sprintf(khlp42, "                  ");
                              sprintf(khlp43, "                  ");
                              sprintf(khlp44, "                  ");
                              khlp();
                              goto helpmenu;
                       case 52:
                              goto helpmenu;
                       default:
                            FadeDown();
                            cout<<"Error' you entered the wrong input\n";
                            delay(1200);
                            goto keyhelp;
                       }

         case 50:
              trblshtng:
              FadeDown();
              cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
              cout<<" ?                          #######################                          บ\n";
              cout<<" ?                          #   Troubleshooting   #                          บ\n";
              cout<<" ?                          #######################                          บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?<<dbvdbsvlm<<"บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?           Û฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿?          บ\n";
              cout<<" ?           ?1. What do those abreviations in keyhelp mean?    ?          บ\n";
              cout<<" ?           ?2. Back to the help menu                          ?          บ\n";
              cout<<" ?           ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ?          บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" ?                                                                           บ\n";
              cout<<" บSelection:                                                                  บ\n";
              cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
              input=getch();
              if ( input == ESC )
              {
                 system("echo [1;37;40m");
                 SetText();
                 exit(1);
              }
              switch ( input ) {
                     case 49:
                            FadeDown();
                            cout<<"\n";
                            cout<<"\n";
                            cout<<"What they mean is:\n";
                            cout<<"\n";
                            cout<<"lef means left\n";
                            cout<<"rig means right\n";
                            cout<<"up means well up\n";
                            cout<<"dow means...there is no dow!?!\n";
                            cout<<"\n";
                            cout<<"squ means square\n";
                            cout<<"cir means circle\n";
                            cout<<"tri means triangle\n";
                            cout<<"x means...nothing to me\n";
                            cout<<"\n";
                            cout<<"Press start to go back.\n";
                            input=getch();
                            if ( input == ESC )
                            {
                               system("echo [1;37;40m");
                               SetText();
                               exit(1);
                            }
                            goto trblshtng;
                     case 50:
                            goto helpmenu;
                     default:
			    FadeDown();
                            cout<<"Error' you entered the wrong input\n";
                            delay(1200);
                            goto helpmenu;
             }
         case 51:
         goto end;
         default:
	     FadeDown();
             cout<<"Error' you entered the wrong input\n";
             delay(1200);
             goto helpmenu;
         }

end:;
}
//-------------------------------------------Win31-----Win95-----Win98---WinXP---------------------------------------------//
void win31()
{


              FadeDown();
              system("echo on");
              cout<<"Thanks for trying dbsW3.1\n";
              cout<<"Gaby_64 from BB\n";
              system("if not exist w31.img echo ERROR: Warning! PRESS ESC NOW! w31.img was not found.");
              delay(2000);
              system("if not exist w31.img echo ERROR: Invalid key you must PUSH SELECT on your PSP");
              system("if not exist w31.img echo PRESS SELECT TO EXIT( ON YOUR PSP )");
              input=getch();
              if ( input == ESC )
              {
                 system("echo [1;37;40m");
                 SetText();
                 exit(1);
              }
              system("imgmount c ./w31.img -t hdd -fs fat -size 512,63,16,");
              system("imgmount c ./w31.img -t hdd -fs fat -size 512,63,16,");
              system("if exist floppy.img imgmount f ./floppy.img -t floppy");
              system("if exist floppy2.img imgmount a ./floppy2.img -t floppy");
              system("if exist drive2.img imgmount b ./drive2.img -t hdd -fs fat");
              system("if exist cdrom.iso imgmount d ./cdrom.iso -t iso");
              system("if exist cdrom2.iso imgmount g ./cdrom2.iso -t iso");
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"!!are you ready for this!!\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"please wait to begin booting w3.1\n";
              delay(5000);
              FadeDown();
              system("boot -l c");
              system("if errorlevel 1 echo ERROR: Warning! c: did not boot succesfuly!");
              system("mount -u c");
              system("mount -u a");
              system("mount -u d");
              system("mount -u b");
              system("mount -u f");
              system("mount -u g");
              system("pause");
}
void win95()
{
              FadeDown();
              system("echo on");
              cout<<"Thanks for trying dbsw95\n";
              cout<<"Gaby_64 from BB\n";
              system("if not exist w95.img echo ERROR: Warning! PRESS ESC NOW! w95.img was not found.");
              delay(2000);
              system("if not exist w95.img echo ERROR: Invalid key you must PUSH SELECT on your PSP");
              system("if not exist w95.img echo PRESS SELECT TO EXIT( ON YOUR PSP )");
              input=getch();
              if ( input == ESC )
              {
                 system("echo [1;37;40m");
                 SetText();
                 exit(1);
              }
              system("imgmount c ./w95.img -t hdd -fs fat -size 512,63,16,");
              system("imgmount c ./w95.img -t hdd -fs fat -size 512,63,16,");
              system("if exist floppy.img imgmount f ./floppy.img -t floppy");
              system("if exist floppy2.img imgmount a ./floppy2.img -t floppy");
              system("if exist drive2.img imgmount b ./drive2.img -t hdd -fs fat");
              system("if exist cdrom.iso imgmount d ./cdrom.iso -t iso");
              system("if exist cdrom2.iso imgmount g ./cdrom2.iso -t iso");
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"!!are you ready for this!!\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"please wait to begin booting w95\n";
              delay(5000);
              FadeDown();
              system("boot -l c");
              system("if errorlevel 1 echo ERROR: Warning! c: did not boot succesfuly!");
              system("mount -u c");
              system("mount -u a");
              system("mount -u d");
              system("mount -u b");
              system("mount -u f");
              system("mount -u g");
              system("pause");
}
void win98()
{

              FadeDown();
              system("echo on");
              cout<<"Thanks for trying dbsw98\n";
              cout<<"Gaby_64 from BB\n";
              system("if not exist w98.img echo ERROR: Warning! PRESS ESC NOW! w98.img was not found.");
              delay(2000);
              system("if not exist w98.img echo ERROR: Invalid key you must PUSH SELECT on your PSP");
              system("if not exist w98.img echo PRESS SELECT TO EXIT( ON YOUR PSP )");
              input=getch();
              if ( input == ESC )
              {
                 system("echo [1;37;40m");
                 SetText();
                 exit(1);
              }
              system("imgmount c ./w98.img -t hdd -fs fat -size 512,63,16,");
              system("imgmount c ./w98.img -t hdd -fs fat -size 512,63,16,");
              system("if exist floppy.img imgmount f ./floppy.img -t floppy");
              system("if exist floppy2.img imgmount a ./floppy2.img -t floppy");
              system("if exist drive2.img imgmount b ./drive2.img -t hdd -fs fat");
              system("if exist cdrom.iso imgmount d ./cdrom.iso -t iso");
              system("if exist cdrom2.iso imgmount g ./cdrom2.iso -t iso");
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"!!are you ready for this!!\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"please wait to begin booting w98\n";
              delay(5000);
              FadeDown();
              system("boot -l c");
              system("if errorlevel 1 echo ERROR: Warning! c: did not boot succesfuly!");
              system("mount -u c");
              system("mount -u a");
              system("mount -u d");
              system("mount -u b");
              system("mount -u f");
              system("mount -u g");
              system("pause");
}
void winXP()
{
              FadeDown();
              system("echo on");
              cout<<"Thanks for trying dbswXP\n";
              cout<<"Gaby_64 from BB\n";
              system("if not exist wXP.img echo ERROR: Warning! PRESS ESC NOW! wXP.img was not found.");
              delay(2000);
              system("if not exist wXP.img echo ERROR: Invalid key you must PUSH SELECT on your PSP");
              system("if not exist wXP.img echo PRESS SELECT TO EXIT( ON YOUR PSP )");
              input=getch();
              if ( input == ESC )
              {
                 system("echo [1;37;40m");
                 SetText();
                 exit(1);
              }
              system("imgmount c ./wXP.img -t hdd -fs fat");
              system("imgmount c ./wXP.img -t hdd -fs fat");
              system("if exist floppy.img imgmount f ./floppy.img -t floppy");
              system("if exist floppy2.img imgmount a ./floppy2.img -t floppy");
              system("if exist drive2.img imgmount b ./drive2.img -t hdd -fs fat");
              system("if exist cdrom.iso imgmount d ./cdrom.iso -t iso");
              system("if exist cdrom2.iso imgmount g ./cdrom2.iso -t iso");
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"!!are you ready for this!!\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"\n";
              cout<<"please wait to begin booting wXP\n";
              delay(5000);
              FadeDown();
              system("boot -l c");
              system("if errorlevel 1 echo ERROR: Warning! c: did not boot succesfuly!");
              system("mount -u c");
              system("mount -u a");
              system("mount -u d");
              system("mount -u b");
              system("mount -u f");
              system("mount -u g");
              system("pause");

}
//---------------------------------------------------------Utility menu----------------------------------------------------//

char txtcol2[20];
char bkgcol2[20];
int comcounter1;
int comcounter2;
int comcounter3;
int itemcounter;
int choice;
char mitem1[25];
char def1mitem1[60];
char def2mitem1[60];
char def3mitem1[60];
char mitem2[25];
char def1mitem2[60];
char def2mitem2[60];
char def3mitem2[60];
char mitem3[25];
char def1mitem3[60];
char def2mitem3[60];
char def3mitem3[60];
char dbsdefcols[50]="echo [1;36;44m[J";
char pof[50];
char mel[50];
char befcol[50];

void utilmenu()
{
  utilmenu:
  FadeDown();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                          #  DBS UTILITYS MENU  #                          บ\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                      Û฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿?                     บ\n";
  cout<<" ?                      ?1. Open file editor         ?                     บ\n";
  cout<<" ?                      ?2. Execute DOS command      ?                     บ\n";
  cout<<" ?                      ?3. Change screen/txt color  ?                     บ\n";
  cout<<" ?                      ?4. Back to the main menu    ?                     บ\n";
  cout<<" ?                      ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ?                     บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บSelection:                                                                  บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
     SetText();
     exit(1);
  }
  switch ( input ) {
         case 49:
                FadeDown();
                cout << "Enter the path or name of the file you want to edit: ";
                cin >> pof;
                sprintf(mel, "mel %s", pof);
                system(mel);
                goto end;
          case 50:
                FadeDown();
                char doscom[60];
                cout << "Enter the command you want to execute: ";
                cin >> doscom;
                system(doscom);
                cout<<"Press any key to continue\n";
                input=getch();
                if ( input == ESC )
                {
                   system("echo [1;37;40m");
                   SetText();
                   exit(1);
                }
                goto utilmenu;
          case 51:
                setcolors:
                FadeDown();
                sprintf(befcol, setcol );
                cout<<"     _____________________________________________________________________   \n";
                cout<<"    |    dark=0   |    red=1    |   green=2   |   yellow=3  |    blue=4   |  \n";
                cout<<"    |_____________|_____________|_____________|_____________|_____________|  \n";
                cout<<"    |  magenta=5  |    aqua=6   |   white=7   |             |             |  \n";
                cout<<"    |_____________|_____________|_____________|_____________|_____________|  \n";
                cout<<"\n";
                if (txtcol==0)
                {
                   sprintf(txtcol2, "dark");
                }
                if (txtcol==1)
                {
                   sprintf(txtcol2, "red");
                }
                if (txtcol==2)
                {
                   sprintf(txtcol2, "green");
                }
                if (txtcol==3)
                {
                   sprintf(txtcol2, "yellow");
                }
                if (txtcol==4)
                {
                   sprintf(txtcol2, "blue");
                }
                if (txtcol==5)
                {
                   sprintf(txtcol2, "magenta");
                }
                if (txtcol==6)
                {
                   sprintf(txtcol2, "aqua");
                }
                if (txtcol==7)
                {
                   sprintf(txtcol2, "white");
                }
                if (bkgcol==0)
                {
                   sprintf(bkgcol2, "dark");
                }
                if (bkgcol==1)
                {
                   sprintf(bkgcol2, "red");
                }
                if (bkgcol==2)
                {
                   sprintf(bkgcol2, "green");
                }
                if (bkgcol==3)
                {
                   sprintf(bkgcol2, "yellow");
                }
                if (bkgcol==4)
                {
                   sprintf(bkgcol2, "blue");
                }
                if (bkgcol==5)
                {
                   sprintf(bkgcol2, "magenta");
                }
                if (bkgcol==6)
                {
                   sprintf(bkgcol2, "aqua");
                }
                if (bkgcol==7)
                {
                   sprintf(bkgcol2, "white");
                }
                cout<<"Current background color is: "<<bkgcol2<<"\n";
                cout<<"\n";
                cout<<"Current txt color is: "<<txtcol2<<"\n";
                cout<<"\n";
                cout<<"Enter the number of the color you want to set to background: ";
                cin>>bkgcol;
                cout<<"\n";
                cout<<"Enter the number of the color you want to set to txt: ";
                cin>>txtcol;
                sprintf(setcol, "echo  [1;3%d;4%dm[J", txtcol, bkgcol );
                cout<<"\n";
                system(setcol);
                cout<<"Are your sure you want to change colors to this (y/n)?";
                input=getch();
                if ( input == ESC )
                {
                   system("echo [1;37;40m");
                   SetText();
                   exit(1);
                }
                if ( input == 110 )
                {
                   sprintf(setcol, befcol );
                   goto setcolors;
                }
                goto utilmenu;
          case 52:
                goto end;
         default:
                 FadeDown();
                 cout<<"Error, you entered the wrong input\n";
                 delay(1200);
                 goto utilmenu;
         }
end:;
}


//-----------------------------------------------End of all DBS functions-------------------------------------------------//

int main()
{
  Initialize();
  clstocol();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?//////////////////////////     /////     /////     ////////////////////////บ\n";
  cout<<" ?////////////////////////// ////  /// ///  ///  ///  ///////////////////////บ\n";
  cout<<" ?////////////////////////// /////  // ///  ///  ////////////////////////////บ\n";
  cout<<" ?////////////////////////// /////  //     /////     ////////////////////////บ\n";
  cout<<" ?////////////////////////// /////  // ///  ////////  ///////////////////////บ\n";
  cout<<" ?////////////////////////// ////  /// ///  ///  ///  ///////////////////////บ\n";
  cout<<" ?//////////////////////////     /////     /////     ////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ?///////////////////////////////////////////////////////////////////////////บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  delay(500);
  clstocol();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                          /////     /////     /////                        บ\n";
  cout<<" ?                          /   //    /   //   //   //                       บ\n";
  cout<<" ?                          /    //   /   //   //                            บ\n";
  cout<<" ?                          /    //   /////     /////                        บ\n";
  cout<<" ?                          /    //   /   //        //                       บ\n";
  cout<<" ?                          /   //    /   //   //   //                       บ\n";
  cout<<" ?                          /////     /////     /////                        บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                 ver of dbs=2,C085     lastmodafied=2008-02-29             บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  delay(1000);

  mainmenu:
  FadeDown();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                          #    DBS MAIN MENU    #                          บ\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                      Û฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿?                     บ\n";
  cout<<" ?                      ?1. Go to Boot Menu          ?                     บ\n";
  cout<<" ?                      ?2. Go to Utility Menu       ?                     บ\n";
  cout<<" ?                      ?3. Go to User Utility Menu  ?                     บ\n";
  cout<<" ?                      ?4. Go to DSBX config Menu   ?                     บ\n";
  cout<<" ?                      ?5. Go to Help Menu          ?                     บ\n";
  cout<<" ?                      ?6. Intro                    ?                     บ\n";
  cout<<" ?                      ?7. Credits                  ?                     บ\n";
  cout<<" ?                      ?8. Exit to DOS              ?                     บ\n";
  cout<<" ?                      ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ?                     บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บSelection:                                                                  บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
     SetText();
     exit(1);
  }
  switch ( input ) {
         case 49:
              goto bootmenu;
         case 50:
              goto utilmenu;
         case 51:
              goto userutilmenu;
         case 52:
              goto dsbxcmenu;
         case 53:
              goto helpmenu;
         case 54:
              goto intro;
         case 55:
              goto credits;
         case 56:
              goto end;
         default:
                 FadeDown();
                 cout<<"Error, you entered the wrong input\n";
                 delay(1200);
                 goto mainmenu;
         }


  utilmenu:
  utilmenu();
  goto mainmenu;

  userutilmenu:
  FadeDown();
  cout<<" ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n";
  cout<<"                             #######################                           \n";
  cout<<"                             #  DBS USERUTIL MENU  #                           \n";
  cout<<"                             #######################                           \n";
  cout<<"                                                                               \n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<"                           1. Add/Remove item to menu                          \n";
  cout<<"                           2. "<< mitem1 <<"                                   \n";
  cout<<"                           3. "<< mitem2 <<"                                   \n";
  cout<<"                           4. "<< mitem3 <<"                                   \n";
  cout<<"                           5. Go back to mainmenu                              \n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<"                                                                               \n";
  cout<<" Selection:                                                                    \n";
  cout<<" ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
        SetText();
            exit(1);
                }
                switch ( input ) {
                       case 49:
                             addremovei:
                             FadeDown();
                             cout<<"Add=1\n";
                             cout<<"Remove=2\n";
                             cout<<"\n";
                             cout<<"Wich one: ";
                             input=getch();
                             if ( input == 50 )
                             {
                                clstocol();
                                cout<<"Wich item do you wish to remove:\n";
                                cout<<""<< mitem1 <<"=1 \n";
                                cout<<""<< mitem2 <<"=2 \n";
                                cout<<""<< mitem3 <<"=3 \n";
                                cout<<"\n";
                                cout<<"Press c to cancel\n";
                                cout<<"Wich one: ";
                                input=getch();
                                if ( input == 49 )
                                {
                                itemcounter=itemcounter-3;
                                comcounter1=0;
                                sprintf(mitem1, "");
                                goto userutilmenu;
                                }
                                if ( input == 50 )
                                {
                                itemcounter=itemcounter-2;
                                comcounter2=0;
                                sprintf(mitem2, "");
                                goto userutilmenu;
                                }
                                if ( input == 51 )
                                {
                                itemcounter=itemcounter-1;
                                comcounter3=0;
                                sprintf(mitem3, "");
                                goto userutilmenu;
                                }
                                if ( input == 99 )
                                {
                                goto addremovei;
                                }

                             }
                             clstocol();
                             if (itemcounter==-1)
                             {
                                itemcounter=2;
                             }
                             if (itemcounter==-2)
                             {
                                itemcounter=1;
                             }
                             if (itemcounter==-3)
                             {
                                itemcounter=0;
                             }
                             if (itemcounter<=-3)
                             {
                                itemcounter=0;
                             }
//--------------------------------------------------Item 1-----------------------------------------------------------------//
                             if (itemcounter==0)
                             {
                             cout << "Enter the name of the menuitem you want to add: ";
                             cin >> mitem1;
                             cout<<"\n";
                             cout << "Enter the command that you want to be exacuted in your menuitem: ";
                             cin >> def1mitem1;
                             cout<<"\n";
                             ++comcounter1;
//--------------------------------------------------COM 1------------------------------------------------------------------//
                             cout << "Do you wish to add another command (yes=1/no=2) ";
                             cin >> choice;
                             if (choice==2) {
                                 ++itemcounter;
                                 goto userutilmenu;
                             }
                             cout<<"\n";
                             cout << "Enter the command that you want to be exacuted in your menuitem: ";
                             cin >> def2mitem1;
                             ++comcounter1;
//--------------------------------------------------COM 2------------------------------------------------------------------//
                             cout << "Do you wish to add another command (yes=1/no=2) ";
                             cin >> choice;
                             if (choice==2) {
                                ++itemcounter;
                                goto userutilmenu;
                             }
                             cout<<"\n";
                             cout << "Enter the command that you want to be exacuted in your menuitem: ";
                             cin >> def3mitem1;
                             ++comcounter1;
//--------------------------------------------------COM 3------------------------------------------------------------------//
                             ++itemcounter;
                             goto userutilmenu;
                             }
//--------------------------------------------------Item 2-----------------------------------------------------------------//
                             if (itemcounter==1)
                             {
                             cout << "Enter the name of the menuitem you want to add: ";
                             cin >> mitem2;
                             cout<<"\n";
                             cout << "Enter the first command that you want to be exacuted in your menuitem: ";
                             cin >> def1mitem2;
                             cout<<"\n";
                             ++comcounter2;
                             cout << "Do you wish to add another command (yes=1/no=2) ";
                             cin >> choice;
                             if (choice==2) {
                                ++itemcounter;
                                goto userutilmenu;
                             }
                             cout<<"\n";
                             cout << "Enter the command that you want to be exacuted in your menuitem: ";
                             cin >> def2mitem2;
                             cout<<"\n";
                             ++comcounter2;
                             cout << "Do you wish to add another command (yes=1/no=2) ";
                             cin >> choice;
                             if (choice==2) {
                                ++itemcounter;
                                goto userutilmenu;
                             }
                             cout<<"\n";
                             cout << "Enter the command that you want to be exacuted in your menuitem: ";
                             cin >> def3mitem2;
                             ++comcounter2;
                             ++itemcounter;
                             goto userutilmenu;
                             }
//---------------------------------------------------Item 3----------------------------------------------------------------//
                             if (itemcounter==2)
                             {
                             cout << "Enter the name of the menuitem you want to add: ";
                             cin >> mitem3;
                             cout<<"\n";
                             cout << "Enter the first command that you want to be exacuted in your menuitem: ";
                             cin >> def1mitem3;
                             cout<<"\n";
                             ++comcounter3;
                             cout << "Do you wish to add another command (yes=1/no=2) ";
                             cin >> choice;
                             if (choice==2) {
                                ++itemcounter;
                                goto userutilmenu;
                             }
                             cout<<"\n";
                             cout << "Enter the command that you want to be exacuted in your menuitem: ";
                             cin >> def2mitem3;
                             cout<<"\n";
                             ++comcounter3;
                             cout << "Do you wish to add another command (yes=1/no=2) ";
                             cin >> choice;
                             if (choice==2) {
                                ++itemcounter;
                                goto userutilmenu;
                             }
                             cout<<"\n";
                             cout << "Enter the command that you want to be exacuted in your menuitem: ";
                             cin >> def3mitem3;
                             ++comcounter3;
                             ++itemcounter;
                             goto userutilmenu;
                             }
//-------------------------------------------------------------------------------------------------------------------------//

                             cout<<"There is no more place in the user util menu. Please remove on item to add one.\n";
                             input=getch();
                             if ( input == ESC )
                             {
                                system("echo [1;37;40m");
                                SetText();
                                exit(1);
                             }
                             goto userutilmenu;
                       case 50:
                              FadeDown();
                              if ( comcounter1 >= 1 ) {
                              system(def1mitem1);
                              }
                              if ( comcounter1 >= 2 ) {
                              system(def2mitem1);
                              }
                              if ( comcounter1 >= 3 ) {
                              system(def3mitem1);
                              }
                              system("pause");
                              goto userutilmenu;
                       case 51:
                              FadeDown();
                              if ( comcounter2 >= 1 ) {
                              system(def1mitem2);
                              }
                              if ( comcounter2 >= 2 ) {
                              system(def2mitem2);
                              }
                              if ( comcounter2 >= 3 ) {
                              system(def3mitem2);
                              }
                              system("pause");
                              goto userutilmenu;
                       case 52:
                              FadeDown();
                              if ( comcounter3 >= 1 ) {
                              system(def1mitem3);
                              }
                              if ( comcounter3 >= 2 ) {
                              system(def2mitem3);
                              }
                              if ( comcounter3 >= 3 ) {
                              system(def3mitem3);
                              }
                              system("pause");
                              goto userutilmenu;
                       case 53:
                              goto mainmenu;
                       default:
                 FadeDown();
                 cout<<"Error, you entered the wrong input\n";
                 delay(1200);
                 goto mainmenu;
  }

  dsbxcmenu:
  dsbxc();
  goto mainmenu;

  helpmenu:
  helpmenu();
  goto mainmenu;

  bootmenu:
  FadeDown();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                          #    DBS BOOT MENU    #                          บ\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                      Û฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿?                     บ\n";
  cout<<" ?                      ?1. Boot windows 3,1         ?                     บ\n";
  cout<<" ?                      ?2. Boot windows 95          ?                     บ\n";
  cout<<" ?                      ?3. Boot windows 98          ?                     บ\n";
  cout<<" ?                      ?4. Boot windows XP          ?                     บ\n";
  cout<<" ?                      ?5. Back to the main menu    ?                     บ\n";
  cout<<" ?                      ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ?                     บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บSelection:                                                                  บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
     SetText();
     exit(1);
  }
  switch ( input ) {
         case 49:
              win31();
              goto mainmenu;
         case 50:
              win95();
              goto mainmenu;
         case 51:
              win98();
              goto mainmenu;
         case 52:
              winXP();
              goto mainmenu;
         case 53:
         goto mainmenu;
         default:
                 FadeDown();
                 cout<<"Error, you entered the wrong input\n";
                 delay(1200);
                 goto bootmenu;
         }

  intro:
  FadeDown();
  cout<<" ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                          #       INTRO         #                          บ\n";
  cout<<" ?                          #######################                          บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?<<dbvdbsvlm<<"บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บDBS is a boot selctor. It anables you to boot any of your windows os easaly บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บand configure dosbox.conf. It also has a game and utility menu wich you can บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" บadd your game to it and start them easaly.                                  บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ?                                                                           บ\n";
  cout<<" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออฝ\n";
  input=getch();
  if ( input == ESC )
  {
     system("echo [1;37;40m");
     SetText();
     exit(1);
  }
  goto mainmenu;

  credits:
  credits();
  goto mainmenu;

  end:
  int e;
  e=0;
  while (e < 5)
  {
  ++e;
  delay(200);
  clstocol();
  cout<<"Exiting   ";
  delay(200);
  clstocol();
  cout<<"Exiting.  ";
  delay(200);
  clstocol();
  cout<<"Exiting.. ";
  delay(200);
  clstocol();
  cout<<"Exiting...";
  }
  delay(200);
  clstocol();
  cout<<"Exiting to DOS";
  delay(1000);
  FadeDown();
  cout<<"To go back to DBS type: dbs";
  delay(500);
  FadeDown();
  system("echo [1;37;40m");
  SetText();
  }
