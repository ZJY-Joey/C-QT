#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <cctype>
#include <QDebug>
#include <QMouseEvent>
#include <cmath>
#include <QString>
#include <QGraphicsDropShadowEffect>
#include <QKeyEvent>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QList<char>expression;

    void ready_to_input(char input);
    //calculate_part
    int priority(char x);

    void calculate(QList<double>& s1, QList<char>& s2);

    void tostack(QList<double>& s1, QList<char>& s2, QList<char> x);

    //边框圆角美化
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
        painter.setBrush(QBrush(Qt::gray));
        painter.setPen(Qt::transparent);
        QRect rect = this->rect();
        rect.setWidth(rect.width() - 1);
        rect.setHeight(rect.height() - 1);
        painter.drawRoundedRect(rect, 15, 15);

    }


    ~MainWindow();

private slots:
    void on_close_clicked();

    void on_minimize_clicked();

    void on_num0_clicked();

    void on_num1_clicked();

    void on_num2_clicked();

    void on_num3_clicked();

    void on_num4_clicked();

    void on_num5_clicked();

    void on_num6_clicked();

    void on_num7_clicked();

    void on_num8_clicked();

    void on_num9_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_mutiply_clicked();

    void on_divide_clicked();

    void on_equal_clicked();

    void on_clear_clicked();

    void on_backspace_clicked();

    void on_left_parenthesis_clicked();

    void on_right_parenthesis_clicked();

    void on_logic_and_clicked();

    void on_parallel_clicked();

    void on_none_clicked();

    void on_dot_clicked();

protected:
    bool eventFilter(QObject *,QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
//    void keyPressEvent(QKeyEvent *);
//    void keyReleaseEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    QPoint mousePoint;
    QPoint windowPoint;


    QGraphicsDropShadowEffect *num0_shadow;
    QGraphicsDropShadowEffect *num1_shadow;
    QGraphicsDropShadowEffect *num2_shadow;
    QGraphicsDropShadowEffect *num3_shadow;
    QGraphicsDropShadowEffect *num4_shadow;
    QGraphicsDropShadowEffect *num5_shadow;
    QGraphicsDropShadowEffect *num6_shadow;
    QGraphicsDropShadowEffect *num7_shadow;
    QGraphicsDropShadowEffect *num8_shadow;
    QGraphicsDropShadowEffect *num9_shadow;
    QGraphicsDropShadowEffect *plus_shadow;
    QGraphicsDropShadowEffect *minus_shadow;
    QGraphicsDropShadowEffect *mutiply_shadow;
    QGraphicsDropShadowEffect *divide_shadow;
    QGraphicsDropShadowEffect *dot_shadow;
    QGraphicsDropShadowEffect *clear_shadow;
    QGraphicsDropShadowEffect *left_parenthesis_shadow;
    QGraphicsDropShadowEffect *right_parenthesis_shadow;
    QGraphicsDropShadowEffect *backspace_shadow;
    QGraphicsDropShadowEffect *logic_and_shadow;
    QGraphicsDropShadowEffect *parallel_shadow;
    QGraphicsDropShadowEffect *none_shadow;

    void addNumButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void removeNumButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void addSignButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void removeSignButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);

    void initButtonShadow(void);
    void setButtonShadow(void);
    void installButtonEventFilter(void);

    void appendText(const QString &s);

    void appendTextAndClearFocus(QPushButton *button, const QString &s);

    void clearButtonFocus(QPushButton *button);
};

#endif // MAINWINDOW_H
