/*
 作者：马三小伙儿
 Date:2016/2/28
 博客：http://www.cnblogs.com/msxh/
*/
#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <phonon>

class BoxGroup;
class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = 0);
    
public slots:
    void startGame();
    void clearFullRows();
    void moveBox();
    void gameOver();
    void restartGame();
    void finishGame();
    void pauseGame();
    void returnGame();
    void aboutToFinish();

private:
BoxGroup *boxGroup;
BoxGroup *nextBoxGroup;
QGraphicsLineItem *topLine;
QGraphicsLineItem *bottomLine;
QGraphicsLineItem *leftLine;
QGraphicsLineItem *rightLine;
QGraphicsTextItem *gameScoreText;//显示分数信息
QGraphicsTextItem *gameLevelText;//显示级别信息
QGraphicsWidget *maskWidget;//遮罩面板
QGraphicsWidget *startButton;//按钮
QGraphicsWidget *finishButton;
QGraphicsWidget *restartButton;
QGraphicsWidget *pauseButton;
QGraphicsWidget *optionButton;
QGraphicsWidget *returnButton;
QGraphicsWidget *helpButton;
QGraphicsWidget *exitButton;
QGraphicsWidget *showMenuButton;
QGraphicsTextItem *gameWelcomeText;//各种文本
QGraphicsTextItem *gamePauseText;
QGraphicsTextItem *gameOverText;
Phonon::MediaObject *backgroundMusic;
Phonon::MediaObject *clearRowSound;
qreal gameSpeed;
QList<int> rows;
void initView();
void initGame();
void updateScore(const int fullRowNum =0);

protected:
void keyPressEvent(QKeyEvent *event);//override keyPressEvent函数
    
};

#endif // MYVIEW_H
