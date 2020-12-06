#include "cview.h"
#include <QGridLayout>
#include <QRect>

CView::CView(QWidget *parent) : QWidget(parent)
{
    textureSys.Init();
    menuSys.Init();
    vector<QLabel*> labelList;
    vector<QPushButton*> buttonList;

    CMenu* currentMenu = menuSys.GetMenu(menuSys.GetCurrentMenuId());
    //text draw
    for(int textid=0;textid<currentMenu->GetTextSize();textid++) {
        QLabel * label = new QLabel(currentMenu->GetText(textid)->text.c_str(),this);
        label->setGeometry(currentMenu->GetText(textid)->pos.x,currentMenu->GetText(textid)->pos.y,currentMenu->GetText(textid)->GetW(),currentMenu->GetText(textid)->GetH());
        labelList.push_back(label);
    }
    //buttons draw
    for(int butid=0;butid<currentMenu->GetButtonSize();butid++) {
        QPushButton * button = new QPushButton(currentMenu->GetButton(butid)->GetText().c_str(),this);
        button->setGeometry(currentMenu->GetButton(butid)->GetPos());
        buttonList.push_back(button);
        connect(button,SIGNAL(released()),this,SLOT(_ChangeMenu()));
    }
    //texture draw

    //into layout
    /*
    QGridLayout * layout = new QGridLayout(this);
    for (int labid=0;labid<labelList.size();labid++) {
        layout->addWidget(labelList[labid],0,labid+1);
    }
    for(int pushbid=0;pushbid<buttonList.size();pushbid++) {
        layout->addWidget(buttonList[pushbid],pushbid+1,0);
    }
    */
}

void CView::_ChangeMenu()
{
    menuSys.SetCurrentMenu(1);

}
