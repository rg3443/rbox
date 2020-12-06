#ifndef CVIEW_H
#define CVIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>

#include "ctexturesystem.h"
#include "cmenusystem.h"
using namespace std;
#include <vector>

class CView : public QWidget {
Q_OBJECT
public:
    explicit CView(QWidget *parent = nullptr);

private:
    CTextureSystem textureSys;
    CMenuSystem menuSys;
private slots:
    void _ChangeMenu();
signals:
};

#endif // CVIEW_H
