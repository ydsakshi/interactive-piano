#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include<windows.h>
#include<string>
#include <sstream>


namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;
using namespace patch;
//void func(){
//         }
//}
struct recunit{
char type;int index;DWORD dw;
};
DWORD starttime;
vector<DWORD>starttimes;
vector<recunit>recording;
vector<string>names;
vector<vector<recunit>>store;
int libraryindex=0,autoplayindex=0;

int vol=100;
float pitch=1.0;
int whitex=66,whitey=130,blackx=90,blacky=130;
bool flagkeyshow=false,recordstart=false,recordstop=false,manwindowopen=false;
//vector<char,int>recording;
char showkeys2[21]="13680QEYIP|8SFHL'CBM";
char showkeys1[30]="`24579-=WRTUO[]79ADGJK;ZXVN,.";
int rgb[17][3]={{255,255,255},{255,0,0},{0,255,0},{0,0,255},{255,255,0},{0,255,255},{255,0,255},{192,192,192},{128,128,128},{128,0,0},{128,128,0},{0,128,0}
                ,{128,0,128},{0,128,128},{0,0,128},{165,42,42},{255,215,0}};
int index=0;
//sf::Keyboard::Key::
using namespace std;
sf::Keyboard::Key keyw[29]={sf::Keyboard::Key::Tilde,sf::Keyboard::Key::Num2,sf::Keyboard::Key::Num4,sf::Keyboard::Key::Num5,sf::Keyboard::Key::Num7,sf::Keyboard::Key::Num9,
sf::Keyboard::Key::Dash,sf::Keyboard::Key::Equal,sf::Keyboard::Key::W,sf::Keyboard::Key::R,sf::Keyboard::Key::T,sf::Keyboard::Key::U,
sf::Keyboard::Key::O,sf::Keyboard::Key::LBracket,sf::Keyboard::Key::RBracket,sf::Keyboard::Key::Numpad7,sf::Keyboard::Key::Numpad9,sf::Keyboard::Key::A,sf::Keyboard::Key::D
,sf::Keyboard::Key::G,sf::Keyboard::Key::J,sf::Keyboard::Key::K,sf::Keyboard::Key::SemiColon,sf::Keyboard::Key::Z,sf::Keyboard::Key::X,
sf::Keyboard::Key::V,sf::Keyboard::Key::N,sf::Keyboard::Key::Comma,sf::Keyboard::Key::Period};

sf::Keyboard::Key keyb[20]={sf::Keyboard::Key::Num1,sf::Keyboard::Key::Num3,sf::Keyboard::Key::Num6,sf::Keyboard::Key::Num8,sf::Keyboard::Key::Num0
                            ,sf::Keyboard::Key::Q,sf::Keyboard::Key::E,sf::Keyboard::Key::Y,sf::Keyboard::Key::I,sf::Keyboard::Key::P,sf::Keyboard::Key::BackSlash,
                            sf::Keyboard::Key::Numpad8,sf::Keyboard::Key::S,sf::Keyboard::Key::F,sf::Keyboard::Key::H,sf::Keyboard::Key::L,sf::Keyboard::Key::Quote,
                            sf::Keyboard::Key::C,sf::Keyboard::Key::B,sf::Keyboard::Key::M};
bool flag=false,flag1=false,autoplaypressed=false;

//void show(){for(auto p:recording) cout<<"("<<p.type<<","<<p.index<<","<<p.dw<<","<<")"<<endl;}



int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow win(sf::VideoMode(1350,350),"PIANO++",sf::Style::None,settings);

//    win.setKeyRepeatEnabled(false);
    win.setPosition(sf::Vector2i(8,50));
    sf::Texture textureb,texturew,texturebh,texturewh,texturebp,texturewp,bar,staff,exitbutton[2],buttonbase,plusbutton,subbutton,plusbuttonp,subbuttonp
    ,keyassist,keyassistp,colorchange,colorchangep,recbutton,recbuttonp,recbuttonin,playbutton,playbuttonp,playbuttonin,stopbutton,stopbuttonp,stopbuttonin,buttonbase2
    ,resetbutton,resetbuttonp,savebutton,savebuttonp,autotext,autoplay,autonext,autodel,autoauto,autotextp,autoplayp,autonextp,autodelp,autoautop,manual,manualp;
//    sf::FloatRect whitebox[36];
//    sf::FloatRect blackbox[25];
    int posw[36][2];
    int posb[25][2];
    float scalew[2]={0.08f, 0.08f};
    float scaleb[2]={0.145f, 0.145f};
    float scalewp[2]={0.130f,0.130f};
    int initialwp[2]={-86,-46};
    sf::SoundBuffer buffer[29],buffer1[20];
    sf::Sound sound[29],sound1[20];
    string path_img="assets/images/";
    string path_aud="assets/audios/";
    string file[29]={"1.mid.wav","2.mid.wav","3.mid.wav","4.mid.wav","5.mid.wav","6.mid.wav","7.mid.wav","8.mid.wav","9.mid.wav","0.mid.wav",
                    "q.mid.wav","w.mid.wav","e.mid.wav","r.mid.wav","t.mid.wav","y.mid.wav","u.mid.wav","i.mid.wav","o.mid.wav","p.mid.wav"
                    ,"a.mid.wav","s.mid.wav","d.mid.wav","f.mid.wav","g.mid.wav","h.mid.wav","j.mid.wav","k.mid.wav","l.mid.wav"
                    };
    string file1[20]={"1s.mid.wav","2s.mid.wav","4s.mid.wav","5s.mid.wav","6s.mid.wav","8s.mid.wav","9s.mid.wav","qs.mid.wav","ws.mid.wav","es.mid.wav",
                      "ts.mid.wav","ys.mid.wav","is.mid.wav","os.mid.wav","ps.mid.wav","ss.mid.wav","ds.mid.wav","gs.mid.wav","hs.mid.wav","js.mid.wav"};
        for(int i=0;i<29;i++)
        {if (!buffer[i].loadFromFile(path_aud + file[i]))
                return -1;
        sound[i].setBuffer(buffer[i]);
        sound[i].setVolume(vol);
        }
        for(int i=0;i<20;i++)
        {if (!buffer1[i].loadFromFile(path_aud + file1[i]))
                return -1;
        sound1[i].setBuffer(buffer1[i]);
        sound1[i].setVolume(vol);
        }
// TEXTURES LOADED
    if (!texturew.loadFromFile(path_img + "white.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!textureb.loadFromFile(path_img + "black.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!bar.loadFromFile(path_img + "bar.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!staff.loadFromFile(path_img + "string.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!exitbutton[0].loadFromFile(path_img + "exitbutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!exitbutton[1].loadFromFile(path_img + "exitbuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!buttonbase.loadFromFile(path_img + "buttonbase.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!plusbutton.loadFromFile(path_img + "subbutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!subbutton.loadFromFile(path_img + "plusbutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!plusbuttonp.loadFromFile(path_img + "subbuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!subbuttonp.loadFromFile(path_img + "plusbuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if (!keyassist.loadFromFile(path_img + "keyassist.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
     if (!keyassistp.loadFromFile(path_img + "keyassistp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!colorchange.loadFromFile(path_img + "colorchange.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!colorchangep.loadFromFile(path_img + "colorchangep.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!recbutton.loadFromFile(path_img + "recordbutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
        if(!recbuttonin.loadFromFile(path_img + "recordbuttoninactive.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
        if(!recbuttonp.loadFromFile(path_img + "recordbuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!buttonbase2.loadFromFile(path_img + "buttonbase2.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!playbutton.loadFromFile(path_img + "playbutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
        if(!playbuttonin.loadFromFile(path_img + "playbuttoninactive.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
        if(!playbuttonp.loadFromFile(path_img + "playbuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!stopbutton.loadFromFile(path_img + "stopbutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
        if(!stopbuttonin.loadFromFile(path_img + "stopbuttoninactive.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
        if(!stopbuttonp.loadFromFile(path_img + "stopbuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
        if(!resetbutton.loadFromFile(path_img + "resetbutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
     if(!resetbuttonp.loadFromFile(path_img + "resetbuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!savebutton.loadFromFile(path_img + "savebutton.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!savebuttonp.loadFromFile(path_img + "savebuttonp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autoauto.loadFromFile(path_img + "autoplay.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autoautop.loadFromFile(path_img + "autoplayp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autotext.loadFromFile(path_img + "textbox.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autodel.loadFromFile(path_img + "remove.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autodelp.loadFromFile(path_img + "removep.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autonext.loadFromFile(path_img + "next.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autonextp.loadFromFile(path_img + "nextp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autoplay.loadFromFile(path_img + "play.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!autoplayp.loadFromFile(path_img + "playp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!manual.loadFromFile(path_img + "manual.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
    if(!manualp.loadFromFile(path_img + "manualp.png"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
        return 0;
    }
//     = GetTickCount();
// FOR ALL TEXTURES
    textureb.setSmooth(true);
    texturew.setSmooth(true);
    bar.setSmooth(true);
    staff.setSmooth(true);
    exitbutton[0].setSmooth(true);
    exitbutton[1].setSmooth(true);
    plusbutton.setSmooth(true);
    plusbuttonp.setSmooth(true);
    subbuttonp.setSmooth(true);
    subbutton.setSmooth(true);
    keyassist.setSmooth(true);
    keyassistp.setSmooth(true);
    colorchange.setSmooth(true);
    colorchangep.setSmooth(true);
    buttonbase.setSmooth(true);
    buttonbase2.setSmooth(true);
    recbutton.setSmooth(true);
    recbuttonp.setSmooth(true);
    recbuttonin.setSmooth(true);
        playbutton.setSmooth(true);
    playbuttonp.setSmooth(true);
    playbuttonin.setSmooth(true);
        stopbutton.setSmooth(true);
    stopbuttonp.setSmooth(true);
    stopbuttonin.setSmooth(true);
    resetbutton.setSmooth(true);
    resetbuttonp.setSmooth(true);
    savebutton.setSmooth(true);
    savebuttonp.setSmooth(true);
        autoauto.setSmooth(true);
    autoautop.setSmooth(true);
        autonext.setSmooth(true);
    autonextp.setSmooth(true);
        autodel.setSmooth(true);
    autodelp.setSmooth(true);
        autoplay.setSmooth(true);
    autoplayp.setSmooth(true);
        autotext.setSmooth(true);
    manual.setSmooth(true);
    manualp.setSmooth(true);
// SPRITES DECLARATION
    sf::Sprite spritew[36]; //whitekeys
    sf::Sprite spriteb[25]; //black
    sf::Sprite b[2],s[5];   //2bar,5staff
    sf::Sprite exit;
    sf::Sprite butb[2],plusb[2],subb[2],longbutb;
    sf::Sprite keyas,color,rec,play,stop,reset,save,aplay,aauto,anext,atext,adel,man;

//TEXTURES ASSIGNED TO SPRITES
    butb[0].setTexture(buttonbase);
    plusb[0].setTexture(plusbutton);
    subb[0].setTexture(subbutton);
    keyas.setTexture(keyassist);
    color.setTexture(colorchange);
    rec.setTexture(recbutton);
    play.setTexture(playbuttonin);
    stop.setTexture(stopbuttonin);
    reset.setTexture(resetbutton);
    save.setTexture(savebutton);
    longbutb.setTexture(buttonbase2);
    aplay.setTexture(autoplay);
    anext.setTexture(autonext);
    atext.setTexture(autotext);
    adel.setTexture(autodel);
    aauto.setTexture(autoauto);
    man.setTexture(manual);

    subb[1].setTexture(subbutton);
    butb[1].setTexture(buttonbase);
    plusb[1].setTexture(plusbutton);

// EVERYTHING RELATED TO TEXTS USED
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        cout<<"ERROR LOADING IMAGE"<<endl;
    }
    sf::Text text1[29],text2[20],exitt,volume,pit,plust[2],minust[2],keyshow,col,recordt,resett,playt,stopt,savet,filename,aplayt,adelt,aautot,anextt,mant;
//            text1[i].setFillColor(sf::Color::Red);
//        text1[i].setStyle(sf::Text::Bold);
//        text1[i].setCharacterSize(13);
////        if(i==0) text1[i].setPosition(whitex,whitey);
//         text1[i].setPosition(posw[i][0]+16,posw[i][1]+165);
//        if(i==15||i==16) {string temp="num";text1[i].setPosition(posw[i][0]+6,posw[i][1]+164);temp+=showkeys1[i];text1[i].setString(temp);}

    exitt.setFont(font);
    exitt.setFillColor(sf::Color::White);
    exitt.setCharacterSize(10);
    exitt.setString("Close");
    exitt.setPosition(1300,43);
        volume.setFont(font);
    volume.setFillColor(sf::Color::White);
    volume.setCharacterSize(15);
    volume.setString("Volume");
    volume.setPosition(1181,22);
        pit.setFont(font);
    pit.setFillColor(sf::Color::White);
    pit.setCharacterSize(15);
    pit.setString("Pitch");
    pit.setPosition(1025,22);
        plust[0].setFont(font);
    plust[0].setFillColor(sf::Color::White);
    plust[0].setCharacterSize(15);
    plust[0].setString("+");
    plust[0].setPosition(1152,22);
        plust[1].setFont(font);
    plust[1].setFillColor(sf::Color::White);
    plust[1].setCharacterSize(15);
    plust[1].setString("+");
    plust[1].setPosition(987,22);
        minust[0].setFont(font);
    minust[0].setFillColor(sf::Color::White);
    minust[0].setCharacterSize(15);
    minust[0].setString("-");
    minust[0].setPosition(1253,22);
        minust[1].setFont(font);
    minust[1].setFillColor(sf::Color::White);
    minust[1].setCharacterSize(15);
    minust[1].setString("-");
    minust[1].setPosition(1088,22);
        col.setFont(font);
    col.setFillColor(sf::Color::White);
    col.setCharacterSize(10);
    col.setString("Color");
    col.setPosition(874,46);
        keyshow.setFont(font);
    keyshow.setFillColor(sf::Color::White);
    keyshow.setCharacterSize(10);
    keyshow.setString("ShowKeys");
    keyshow.setPosition(912,46);
        playt.setFont(font);
    playt.setFillColor(sf::Color::White);
    playt.setCharacterSize(10);
    playt.setString("Play");
    playt.setPosition(653,22);
        stopt.setFont(font);
    stopt.setFillColor(sf::Color::White);
    stopt.setCharacterSize(10);
    stopt.setString("Stop");
    stopt.setPosition(593,22);
        recordt.setFont(font);
    recordt.setFillColor(sf::Color::White);
    recordt.setCharacterSize(10);
    recordt.setString("Record");
    recordt.setPosition(533,22);
        resett.setFont(font);
    resett.setFillColor(sf::Color::White);
    resett.setCharacterSize(10);
    resett.setString("Reset");
    resett.setPosition(725,13);
        savet.setFont(font);
    savet.setFillColor(sf::Color::White);
    savet.setCharacterSize(10);
    savet.setString("Save");
    savet.setPosition(725,30);
        filename.setFont(font);
    filename.setFillColor(sf::Color(128,128,128));
    filename.setCharacterSize(15);
    filename.setString("");
    filename.setPosition(208,25);
        aplayt.setFont(font);
    aplayt.setFillColor(sf::Color::White);
    aplayt.setCharacterSize(10);
    aplayt.setString("Play");
    aplayt.setPosition(345,45);
        adelt.setFont(font);
    adelt.setFillColor(sf::Color::White);
    adelt.setCharacterSize(10);
    adelt.setString("Clear");
    adelt.setPosition(380,45);
        anextt.setFont(font);
    anextt.setFillColor(sf::Color::White);
    anextt.setCharacterSize(10);
    anextt.setString("Next");
    anextt.setPosition(165,45);
        aautot.setFont(font);
    aautot.setFillColor(sf::Color::White);
    aautot.setCharacterSize(10);
    aautot.setString("Auto");
    aautot.setPosition(130,45);
        mant.setFont(font);
    mant.setFillColor(sf::Color::White);
    mant.setCharacterSize(10);
    mant.setString("How");
    mant.setPosition(22,43);

//  POSITIONING OF SPRITES

    b[0].setTexture(bar);b[1].setTexture(bar);
    exit.setTexture(exitbutton[0]);
    for(int i=0;i<5;i++)
        s[i].setTexture(staff);
//    spritew[0].scale(0.2f, 0.2f);
//    spritew[1].scale(0.2f, 0.2f);
    for(int i=0;i<36;i++)
        spritew[i].setTexture(texturew);
    for(int i=0;i<25;i++)
        spriteb[i].setTexture(textureb);

    for(int i=0; i<36; i++)
    {
        if(i>=25)
        {
            spritew[i].setTextureRect(sf::IntRect(0,0,224,1024));
            spritew[i].scale(0.1875f, 0.1875f);
        }
        else
        {
            spritew[i].setTextureRect(sf::IntRect(0,0,224,1024));
            spriteb[i].setTextureRect(sf::IntRect(sf::IntRect(0,0,178,713)));
            spritew[i].scale(0.1875f, 0.1875f);
            spriteb[i].scale(0.1875f, 0.1875f);

        }
    }


    b[0].setPosition(13,60);
    b[1].setPosition(1293,60);

    int staffx=51,staffy=123;
    for(int i=0;i<5;i++)
        {
        s[i].setPosition(staffx,staffy);
        staffy-=14;
        }
    exit.setPosition(1298,15);
    butb[0].setPosition(1135,10);
    plusb[0].setPosition(1145,20);
    subb[0].setPosition(1245,20);
    keyas.setPosition(920,15);
    color.setPosition(870,15);
    longbutb.setPosition(500,10);
    rec.setPosition(514,21);
    stop.setPosition(574,21);
    play.setPosition(634,21);
    reset.setPosition(700,13);
    save.setPosition(700,30);
    aauto.setPosition(130,20);
    anext.setPosition(165,20);
    atext.setPosition(200,20);
    aplay.setPosition(345,20);
    adel.setPosition(380,20);
    man.setPosition(17,18);
//    rec.setPosition()

    butb[1].setPosition(970,10);
    plusb[1].setPosition(980,20);
    subb[1].setPosition(1080,20);

    posw[0][0]=whitex;
    posw[0][1]=whitey;
    posb[0][0]=blackx;
    posb[0][1]=blacky;
    spritew[0].setPosition(whitex,whitey);
    spriteb[0].setPosition(blackx,blacky);

    for(int i=1; i<36; i++)
    {
        if((i-3)%7==0 || (i>0 && i%7==0))
        {
            whitex+=42;
            posw[i][0]=whitex;
            posw[i][1]=whitey;
            spritew[i].setPosition(whitex,whitey);
        }
        else
        {
            whitex+=42;
            posw[i][0]=whitex;
            posw[i][1]=whitey;
            spritew[i].setPosition(whitex,whitey);
        }

    }
    posw[35][0]=whitex;
    posw[35][1]=whitey;
    spritew[35].setPosition(whitex,whitey);
    for(int i=1; i<25; i++)
    {
        if((i-2)%5==0 || (i>0 && i%5==0))
        {
            blackx+=84;
            posb[i][0]=blackx;
            posb[i][1]=blacky;
            spriteb[i].setPosition(blackx,blacky);
        }
        else
        {
            blackx+=42;
            posb[i][0]=blackx;
            posb[i][1]=blacky;
            spriteb[i].setPosition(blackx,blacky);
        }

    }
//  MAPPING KEYS FOR PIANO KEYS
        for(int i=0;i<29;i++)
        {
        text1[i].setFont(font);
        text1[i].setFillColor(sf::Color::Red);
        text1[i].setStyle(sf::Text::Bold);
        text1[i].setCharacterSize(13);
//        if(i==0) text1[i].setPosition(whitex,whitey);
         text1[i].setPosition(posw[i][0]+16,posw[i][1]+165);
        if(i==15||i==16) {string temp="num";text1[i].setPosition(posw[i][0]+6,posw[i][1]+164);temp+=showkeys1[i];text1[i].setString(temp);}
        else text1[i].setString(showkeys1[i]);
        }

    for(int i=0;i<20;i++)
        {
        text2[i].setFont(font);
        text2[i].setFillColor(sf::Color::Red);
        text2[i].setStyle(sf::Text::Bold);
        text2[i].setCharacterSize(11);
//        if(i==0) text2[i].setPosition(blackx,blacky);
         text2[i].setPosition(posb[i][0]+13,posb[i][1]+110);
        if(i==11) {string temp="num";text2[i].setPosition(posb[i][0]+2,posb[i][1]+110);temp+=showkeys2[i];text2[i].setString(temp);}//cout<<"value="<<temp<<endl;}
        else
            {text2[i].setString(showkeys2[i]);
//            cout<<"value="<<showkeys2[i]<<endl;
            }
        }


//sf::SoundBuffer buffer,buffer1;
//if (!buffer.loadFromFile("g.mid.wav"))
//        return -1;
//if (!buffer1.loadFromFile("t.mid.wav"))
//        return -1;
//sf::Sound sound,sound1;
//sound.setVolume(100);
//sound.setBuffer(buffer);
//sound1.setVolume(100);
//sound1.setBuffer(buffer1);
//sound.play();
//Sleep(300);
////sf::sleep(sf::Time(sf::seconds(3.0f)));
//sound1.play();
//sf::sleep(sf::Time(sf::seconds(3.0f)));
//
    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::KeyPressed:
                for(int i=0;i<29;i++)
                    {
                        if(event.key.code==keyw[i])
                        {
                            sound[i].play();
                            spritew[i].setTextureRect(sf::IntRect(448,0,224,1024));
                            if(recordstart) {recording.push_back({'w',i,GetTickCount()});}
                        }
                    }
                for(int i=0;i<20;i++)
                    {
                        if(event.key.code==keyb[i])
                        {
                            sound1[i].play();
                            spriteb[i].setTextureRect(sf::IntRect(178,0,178,713));
                            if(recordstart) {recording.push_back({'b',i,GetTickCount()});}
                        }
                    }
                break;
            case sf::Event::KeyReleased:
                    for(int i=0;i<29;i++)
                    {
                        if(event.key.code==keyw[i])
                        {
//                            cout<<"Released\n";
                            spritew[i].setTextureRect(sf::IntRect(0,0,224,1024));
                        }
                    }
                    for(int i=0;i<20;i++)
                    {
                        if(event.key.code==keyb[i])
                        {
                            spriteb[i].setTextureRect(sf::IntRect(0,0,178,713));
                        }
                    }
            case sf::Event::MouseMoved:
                for(int i=0;i<20;i++)
                    {
                        if((spriteb[i].getGlobalBounds()).contains(event.mouseMove.x,event.mouseMove.y))
                        {
                            spriteb[i].setTextureRect(sf::IntRect(178,0,178,713));
                            flag1=true;
                        }
                        else
                        {
                            spriteb[i].setTextureRect(sf::IntRect(0,0,178,713));
                            flag1=false;
                        }
                    }
                if(!flag1)
                {for(int i=0;i<29;i++)
                    {
                        if((spritew[i].getGlobalBounds()).contains(event.mouseMove.x,event.mouseMove.y))
                        {
                            spritew[i].setTextureRect(sf::IntRect(224,0,224,1024));
                            flag1=true;
                        }
                        else
                        {
                            spritew[i].setTextureRect(sf::IntRect(0,0,224,1024));
                            flag1=false;
                        }
                    }
                }
                    break;
            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left && (exit.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    exit.setTexture(exitbutton[1]);
//                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(!manwindowopen && event.mouseButton.button == sf::Mouse::Left && (man.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    man.setTexture(manualp);
                }
                if(store.size() && event.mouseButton.button == sf::Mouse::Left && (aauto.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {
                    aauto.setTexture(autoautop);
                    if(!autoplaypressed)
                    autoplaypressed=true;
                    else autoplaypressed=false;
                    }
                if(store.size() && autoplaypressed && event.mouseButton.button == sf::Mouse::Left && (anext.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        anext.setTexture(autonextp);

                        autoplayindex=(autoplayindex+1)%names.size();
                    }
                if(store.size() && autoplaypressed && event.mouseButton.button == sf::Mouse::Left && (aplay.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {
                    aplay.setTexture(autoplayp);
                    }
                if(store.size()>0 && autoplaypressed && event.mouseButton.button == sf::Mouse::Left && (adel.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {

                        adel.setTexture(autodelp);
                        if(store.size()>0){
                        int p=store.size();
                        store.erase(store.begin()+autoplayindex);
                        names.erase(names.begin()+autoplayindex);
                        starttimes.erase(starttimes.begin()+autoplayindex);
                        if(autoplayindex-1>=0)
                        autoplayindex=(autoplayindex-1)%p;
                        }
                    }
                if( recordstop && event.mouseButton.button == sf::Mouse::Left && (save.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    save.setTexture(savebuttonp);
                    string temp="My_Recording";
                    string temp1=to_string(libraryindex);
                    temp.append(temp1);
                    store.push_back(recording);
                    names.push_back(temp);
                    libraryindex+=1;
                    recording.clear();
                    recordstart=false;
                    recordstop=false;
                }
                if( recordstop && event.mouseButton.button == sf::Mouse::Left && (reset.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    reset.setTexture(resetbuttonp);
                    recording.clear();
                    recordstart=false;
                    recordstop=false;
                }
                if(!recordstart && event.mouseButton.button == sf::Mouse::Left && (rec.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    rec.setTexture(recbuttonp);
                    starttime=GetTickCount();
                    starttimes.push_back(starttime);
                    recordstart=true;
                }
                if(recordstop && event.mouseButton.button == sf::Mouse::Left && (play.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    play.setTexture(playbuttonp);
                }
                 if(recordstart && !recordstop && event.mouseButton.button == sf::Mouse::Left && (stop.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    stop.setTexture(stopbuttonp);
                    recordstop=true;
                    recordstart=false;
                }
                if(event.mouseButton.button == sf::Mouse::Left && (color.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {
                    color.setTexture(colorchangep);
                    index=(index+1)%(17);
                    }
                if(event.mouseButton.button == sf::Mouse::Left && (keyas.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    keyas.setTexture(keyassistp);
                    if(flagkeyshow==false)
                    {
                        flagkeyshow=true;
                    }
                    else
                    {
                    flagkeyshow=false;
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left && (plusb[0].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    if(vol<100)
                    vol+=1;
                    plusb[0].setTexture(plusbuttonp);
                    for(int i=0;i<29;i++)
                        {
                        sound[i].setVolume(vol);
                        }
                    for(int i=0;i<20;i++)
                        {
                        sound1[i].setVolume(vol);
                        }
//                    cout<<vol<<endl;
                        //                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(event.mouseButton.button == sf::Mouse::Left && (plusb[1].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    pitch+=0.1;
                    plusb[1].setTexture(plusbuttonp);
                    for(int i=0;i<29;i++)
                        {
                        sound[i].setPitch(pitch);
                        }
                    for(int i=0;i<20;i++)
                        {
                        sound1[i].setPitch(pitch);
                        }
//                    cout<<vol<<endl;
                        //                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(event.mouseButton.button == sf::Mouse::Left && (subb[0].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    if(vol>0)
                    vol-=1;
                    subb[0].setTexture(subbuttonp);
                    for(int i=0;i<29;i++)
                        {
                        sound[i].setVolume(vol);
                        }
                    for(int i=0;i<20;i++)
                        {
                        sound1[i].setVolume(vol);
                        }
//                    cout<<vol<<endl;
                        //                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(event.mouseButton.button == sf::Mouse::Left && (subb[1].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    if(pitch>0)
                    pitch-=0.1;
                    subb[1].setTexture(subbuttonp);
                    for(int i=0;i<29;i++)
                        {
                        sound[i].setPitch(pitch);
                        }
                    for(int i=0;i<20;i++)
                        {
                        sound1[i].setPitch(pitch);
                        }
                }
                for(int i=0;i<20;i++)
                    {
                        if(event.mouseButton.button == sf::Mouse::Left && (spriteb[i].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                        {
                            spriteb[i].setTextureRect(sf::IntRect(356,0,178,713));
                            sound1[i].play();
                            if(recordstart) {recording.push_back({'b',i,GetTickCount()});}
                            flag=true;
                        }
                    }
                if(!flag){
                for(int i=0;i<29;i++)
                    {
                        if(event.mouseButton.button == sf::Mouse::Left && (spritew[i].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                        {
                            spritew[i].setTextureRect(sf::IntRect(448,0,224,1024));
                            sound[i].play();
                            if(recordstart) {recording.push_back({'w',i,GetTickCount()});}
                            flag=true;
                        }
                    }
                }
                break;
            case sf::Event::MouseButtonReleased:
                 if(event.mouseButton.button == sf::Mouse::Left && (exit.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
//                    exit.setTexture(exitbutton[0]);
                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(!manwindowopen && event.mouseButton.button == sf::Mouse::Left && (man.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    manwindowopen=true;
                    man.setTexture(manual);
                    sf::RenderWindow wn(sf::VideoMode(500,500), "INSTRUCTIONS");
                    sf::Text help;
                    help.setFont(font);
                    help.setFillColor(sf::Color::White);
                    help.setCharacterSize(25);
                    help.setString("INSTRUCTIONS:- \nThe player can simply interact with Piano \nusing mouse/keyboard and can also use\n record option for his/her tune \n and either save or reset it. \n On saving,the tune can be played\n later on using the autoplay option.\n");
                    help.setPosition(0,0);
                             while(wn.isOpen())
                             {    sf::Event event1;
                                    while (wn.pollEvent(event1))
                                        {
                                            switch (event1.type)
                                            {
                                                case sf::Event::Closed:
                                                wn.close();
                                                manwindowopen=false;
                                                break;
                                                default:break;
                                            }
                                        }
                                wn.clear(sf::Color::Black);
                                wn.draw(help);
                                wn.display();
                             }

                }
                if(event.mouseButton.button == sf::Mouse::Left && (aauto.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {aauto.setTexture(autoauto);}
                if(event.mouseButton.button == sf::Mouse::Left && (anext.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {anext.setTexture(autonext);}
                if(store.size() && autoplaypressed && event.mouseButton.button == sf::Mouse::Left && (aplay.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {aplay.setTexture(autoplay);
                    for(int i=0;i<store[autoplayindex].size();i++)
                    {
                        if(i==0) {Sleep(store[autoplayindex][i].dw-starttimes[autoplayindex]);if(store[autoplayindex][i].type=='b') sound1[store[autoplayindex][i].index].play();
                                                                    else sound[store[autoplayindex][i].index].play();}
                        else
                        {
                            Sleep(store[autoplayindex][i].dw-store[autoplayindex][i-1].dw);if(store[autoplayindex][i].type=='b') sound1[store[autoplayindex][i].index].play();
                                                                    else sound[store[autoplayindex][i].index].play();
                        }
                    }}
                if(event.mouseButton.button == sf::Mouse::Left && (adel.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {adel.setTexture(autodel);}
                if(event.mouseButton.button == sf::Mouse::Left && (save.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    save.setTexture(savebutton);
                if(event.mouseButton.button == sf::Mouse::Left && (rec.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    rec.setTexture(recbutton);
                if(event.mouseButton.button == sf::Mouse::Left && (reset.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    reset.setTexture(resetbutton);
                if(recordstop && event.mouseButton.button == sf::Mouse::Left && (play.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        play.setTexture(playbutton);
                        for(int i=0;i<recording.size();i++)
                    {
                        if(i==0) {Sleep(recording[i].dw-starttime);if(recording[i].type=='b') sound1[recording[i].index].play();
                                                                    else sound[recording[i].index].play();}
                        else
                        {
                            Sleep(recording[i].dw-recording[i-1].dw);if(recording[i].type=='b') sound1[recording[i].index].play();
                                                                    else sound[recording[i].index].play();
                        }
                    }
                    }
                if(event.mouseButton.button == sf::Mouse::Left && (stop.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    stop.setTexture(stopbutton);
                if(event.mouseButton.button == sf::Mouse::Left && (color.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                    color.setTexture(colorchange);
                if(event.mouseButton.button == sf::Mouse::Left && (plusb[0].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    plusb[0].setTexture(plusbutton);
//                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(event.mouseButton.button == sf::Mouse::Left && (keyas.getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    keyas.setTexture(keyassist);
//                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(event.mouseButton.button == sf::Mouse::Left && (plusb[1].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    plusb[1].setTexture(plusbutton);
//                    win.close();
//                    exit.setPosition(1298,15);
                }
                if(event.mouseButton.button == sf::Mouse::Left && (subb[0].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    subb[0].setTexture(subbutton);
//                    win.close();
//                    exit.setPosition(1298,15);
                }
                 if(event.mouseButton.button == sf::Mouse::Left && (subb[1].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                {
                    subb[1].setTexture(subbutton);
//                    win.close();
//                    exit.setPosition(1298,15);
                }
                for(int i=0;i<20;i++)
                    {
                        if(event.mouseButton.button == sf::Mouse::Left && (spriteb[i].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                        {
                            spriteb[i].setTextureRect(sf::IntRect(0,0,178,713));
                            flag=false;
                        }
                    }
                if(flag){
                for(int i=0;i<29;i++)
                    {
                        if(event.mouseButton.button == sf::Mouse::Left && (spritew[i].getGlobalBounds()).contains(event.mouseButton.x,event.mouseButton.y))
                        {
                            spritew[i].setTextureRect(sf::IntRect(0,0,224,1024));
                            flag=false;
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
        win.clear(sf::Color::Black);
//        win.clear();
        for(int i=0;i<5;i++)
            win.draw(s[i]);
        for(int i=0; i<29; i++)
            win.draw(spritew[i]);
        for(int i=0; i<20; i++)
            win.draw(spriteb[i]);
//        win.draw(s[0]);
        win.draw(b[0]);
        win.draw(b[1]);
        win.draw(exit);
        win.draw(keyas);
        win.draw(color);

        for(int i=0;i<2;i++)
        {
        win.draw(butb[i]);
        win.draw(plusb[i]);
        win.draw(subb[i]);
        }

        if(flagkeyshow){
        for(int i=0;i<29;i++) win.draw(text1[i]);
        for(int i=0;i<20;i++) win.draw(text2[i]);
        }

        win.draw(longbutb);win.draw(rec);win.draw(stop);win.draw(play);win.draw(reset);
        win.draw(save);
        b[0].setColor(sf::Color(rgb[index][0],rgb[index][1],rgb[index][2]));
        b[1].setColor(sf::Color(rgb[index][0],rgb[index][1],rgb[index][2]));

        for(int i=0;i<5;i++){s[i].setColor(sf::Color(rgb[index][0],rgb[index][1],rgb[index][2]));}
        win.draw(exitt);win.draw(volume);win.draw(pit);win.draw(plust[0]);win.draw(plust[1]);win.draw(minust[0]);win.draw(minust[1]);win.draw(col);win.draw(keyshow);
        win.draw(recordt);win.draw(stopt);win.draw(playt);win.draw(resett);win.draw(savet);win.draw(atext);win.draw(anext);win.draw(aauto);win.draw(aplay);win.draw(adel);
        win.draw(anextt);
        win.draw(aautot);
        win.draw(aplayt);
        win.draw(adelt);
        if(names.size()>0 && autoplaypressed) filename.setString(names[autoplayindex]);
        if(names.size()>0 && autoplaypressed)
        win.draw(filename);

        win.draw(man);win.draw(mant);
        win.display();
    }
    return 0;
}

