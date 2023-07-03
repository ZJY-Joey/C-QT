#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口

    setWindowFlags(windowFlags() | Qt::FramelessWindowHint); //去掉标题栏函数
    ui->box->setAlignment(Qt::AlignRight);  //右对齐
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clearButtonFocus(QPushButton *button)
{
    button->clearFocus();
}

void MainWindow::appendText(const QString &s)
{
    if(ui->box->text() == "0")
        ui->box->setText(s);
    else
        ui->box->setText(ui->box->text()+s);
}

void MainWindow::appendTextAndClearFocus(QPushButton *button, const QString &s)
{
    appendText(s);
    button->clearFocus();
}

void MainWindow::on_close_clicked()
{
    exit(0);
}

void MainWindow::ready_to_input(char input)
{
    if(expression.size() == 0 && ( isdigit(input) || input == '!' || input == '(' ))
        ui->box->clear();
}

void MainWindow::on_minimize_clicked()
{
    MainWindow::showMinimized();
}

void MainWindow::on_num0_clicked()
{
    if(expression.size() == 0)
        return;
    if(expression.size() == 1 && expression[0] == '0')
        return;
    expression.append('0');
    appendTextAndClearFocus(ui->num0 , "0");
}

void MainWindow::on_num1_clicked()
{
    ready_to_input('1');
    expression.append('1');
    appendTextAndClearFocus(ui->num1 , "1");
}

void MainWindow::on_num2_clicked()
{
    ready_to_input('2');
    expression.append('2');
    appendTextAndClearFocus(ui->num2 , "2");
}

void MainWindow::on_num3_clicked()
{
    ready_to_input('3');
    expression.append('3');
    appendTextAndClearFocus(ui->num3 , "3");
}

void MainWindow::on_num4_clicked()
{
    ready_to_input('4');
    expression.append('4');
    appendTextAndClearFocus(ui->num4 , "4");
}

void MainWindow::on_num5_clicked()
{
    ready_to_input('5');
    expression.append('5');
    appendTextAndClearFocus(ui->num5 , "5");
}

void MainWindow::on_num6_clicked()
{
    ready_to_input('6');
    expression.append('6');
    appendTextAndClearFocus(ui->num6 , "6");
}

void MainWindow::on_num7_clicked()
{
    ready_to_input('7');
    expression.append('7');
    appendTextAndClearFocus(ui->num7 , "7");
}

void MainWindow::on_num8_clicked()
{
    ready_to_input('8');
    expression.append('8');
    appendTextAndClearFocus(ui->num8 , "8");
}

void MainWindow::on_num9_clicked()
{
    ready_to_input('9');
    expression.append('9');
    appendTextAndClearFocus(ui->num9 , "9");
}


void MainWindow::on_dot_clicked()
{
    if(expression.size() == 0 )
    {
        ui->box->clear();
        expression.append('0');
        expression.append('.');
        appendTextAndClearFocus(ui->logic_and , "0.");
    }
    else
    {
        expression.append('.');
        appendText(".");
       clearButtonFocus(ui->dot);
    }
}


void MainWindow::on_plus_clicked()
{
    if(expression.size() == 0 )
    {
        ui->box->clear();
        expression.append('0');
        expression.append('+');
        appendTextAndClearFocus(ui->plus , "0+");
    }
    else
    {
        expression.append('+');
        appendTextAndClearFocus(ui->plus , "+");
    }

}

void MainWindow::on_minus_clicked()
{
    if(expression.size() == 0 )
    {
        ui->box->clear();
        expression.append('0');
        expression.append('-');
        appendTextAndClearFocus(ui->minus , "0-");
    }
    else
    {
        expression.append('-');
        appendText("-");
        clearButtonFocus(ui->minus);
    }

}

void MainWindow::on_mutiply_clicked()
{
    if(expression.size() == 0 )
    {
        ui->box->clear();
        expression.append('0');
        expression.append('*');
        appendTextAndClearFocus(ui->plus , "0×");
    }
    else
    {
        expression.append('*');
        appendText("×");
        clearButtonFocus(ui->mutiply);
    }

}

void MainWindow::on_divide_clicked()
{
    if(expression.size() == 0 )
    {
        ui->box->clear();
        expression.append('0');
        expression.append('/');
        appendTextAndClearFocus(ui->plus , "0÷");
    }
    else
    {
        expression.append('/');
        appendText("÷");
       clearButtonFocus(ui->divide);
    }

}

void MainWindow::on_left_parenthesis_clicked()
{
    ready_to_input('(');
    expression.append('(');
    appendText("(");
    clearButtonFocus(ui->left_parenthesis);
}

void MainWindow::on_right_parenthesis_clicked()
{
    ready_to_input(')');
    expression.append(')');
    appendText(")");
    clearButtonFocus(ui->right_parenthesis);
}

void MainWindow::on_logic_and_clicked()
{
    if(expression.size() == 0 )
    {
        ui->box->clear();
        expression.append('0');
        expression.append('&');
        appendTextAndClearFocus(ui->logic_and , "0&&");
    }
    else
    {
        expression.append('&');
        appendText("&&");
       clearButtonFocus(ui->logic_and);
    }
}

void MainWindow::on_parallel_clicked()
{
    if(expression.size() == 0 )
    {
        ui->box->clear();
        expression.append('0');
        expression.append('|');
        appendTextAndClearFocus(ui->parallel , "0||");
    }
    else
    {
        expression.append('|');
        appendText("||");
       clearButtonFocus(ui->parallel);
    }
}

void MainWindow::on_none_clicked()
{
    ready_to_input('!');
    expression.append('!');
    appendText("!");
    clearButtonFocus(ui->none);
}

void MainWindow::on_equal_clicked()
{
    if(expression.size() == 0)
            return;
    appendText("=");
    QList<double> x1;
    QList<char> x2;
    expression.append('#');
    tostack(x1,x2,expression);
            //以下方法都不可行
            //方法一
            //double ans = tostack(x1,x2,expression);
            //ui->box->setText(QString("%1").arg(ans));//显示结果
            //方法二
            //    double ans = tostack(x1,x2,expression);
            //    QString show_ans = QString::number(ans);
            //    appendText(show_ans);
            //方法三
    clearButtonFocus(ui->equal);
}

void MainWindow::on_backspace_clicked()
{
    if(ui->box->text() != "0")
    {
        ui->box->setReadOnly(false);
        ui->box->setText(ui->box->text().size() != 1 ? ui->box->text().mid(0,ui->box->text().size()-1) : "0");
        ui->box->setReadOnly(true);
        ui->backspace->clearFocus();
        if(expression[expression.size() - 1] != '=')
        expression.removeLast();
    }
}


void MainWindow::on_clear_clicked()
{
    expression.clear();
    ui->box->clear();
    appendTextAndClearFocus(ui->num0 , "0");
}

//CALCULATE_PART

int MainWindow::priority(char x)
{
    if (x == '#')
            return -3;
        else if (x == '|')
            return -2;
        else if (x == '&')
            return -1;
        else if (x == '(' || x == ')')
            return 1;
        else if (x == '-' || x == '+')
            return 2;
        else if (x == '*' || x == '/')
            return 3;
        else if (x == '!')
            return 4;

        else
            return 0;
}


void MainWindow::calculate(QList<double>& s1, QList<char>& s2)
{
    char x;
    x = s2[s2.size() - 1]; s2.removeLast();
    //单目运算符
        if (x == '!')
        {
            double a = s1[s1.size() - 1]; s1.removeLast();
            if (a != 0)
                s1.append(0);
            else s1.append(1);
            return;
        }

    //双目运算符
    double a, b;
    a = s1[s1.size() - 1]; s1.removeLast();
    b = s1[s1.size() - 1]; s1.removeLast();

    if (x == '+')
        s1.append(a + b);
    if (x == '-')
        s1.append(b - a);
    if (x == '*')
        s1.append(a * b);
    if (x == '/' && a != 0)
        s1.append(b / a);
    if (x == '&')
        s1.append(a && b);
    if (x == '|')
        s1.append(a || b);

}

//进栈出栈处理部分
void MainWindow::tostack(QList<double>& s1, QList<char>& s2, QList<char> x)
{
    s2.append('#');

    //检查专用
//    for(int i =  0 ; i < x.size() ; i++)
//    {
//        qDebug()<<x[i]<<" ";
//    }

    for (int i = 0; i < x.size(); i++)
    {
        if (isdigit(x[i]))
        {
            if (!s1.empty() && isdigit(x[i - 1]))
            {
                double temp;
                temp = s1[s1.size() - 1];
                s1.removeLast();
                s1.append(temp * 10 + x[i] - '0');
            }
            else
                s1.append(x[i] - '0');
        }
        else if (x[i] == '.')
                {
                    if(i < x.size() - 1 && s1.size() >= 1)
                    {
                    double temp = s1[s1.size() - 1]; s1.removeLast();
                    int j;
                    for (j = 1; isdigit(x[i + j]); j++)
                        temp += pow(0.1, j) * (x[i + j] - '0');
                    s1.append(temp);
                    i += j - 1;
                    }
                    else
                    {
                        ui->box->clear();
                        ui->box->setText("ERROR");
                        return;
                    }
                }
        else
        {
            char top;  //设置待入栈元素
            top = s2[s2.size() - 1];
            if (x[i] == '(')
            {
                s2.append(x[i]);
            }
            else if (priority(x[i]) >= priority(top))//当待入栈元素优先级高于栈顶元素时
                s2.append(x[i]);
            else
            {
                while (!(priority(x[i]) > priority(top)))
                {
                    //首先排除算式进行到结尾的情况
                    if (x[i] == '#' && top == '#')
                    {
                        if(s1.size() == 1)
                        {
                        double answer;
                        answer = s1[s1.size() - 1];
                        QString ans=QString::number(answer);
                        appendText(ans);
                        return;
                        }
                        else
                        {
                            ui->box->clear();
                            ui->box->setText("ERROR");
                            return;
                        }
                    }
                    //再排除括号内算式进行完
                    if (top == '(' && x[i] == ')')
                    {
                        s2.removeLast();
                        top = s2[s2.size() - 1];
                        i++;
                        continue;
                    }
                    else
                    {
                        char temp = s2[s2.size() - 1];
                        if ((temp == '+'|| temp == '-' || temp == '*' || temp == '/' || temp == '&' || temp == '|') && s1.size() < 2)
                        {
                            ui->box->clear();
                            ui->box->setText("ERROR");
                            return;
                        }
                        calculate(s1, s2);
                        top = s2[s2.size() - 1];
                    }
                }
                s2.append(x[i]);
            }
        }
    }
    return;
}

//美化
//解决鼠标无法拖动窗口移动的问题
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mousePoint = event->globalPos();
        windowPoint = frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(windowPoint + event->globalPos() - mousePoint);
    }
}


//增设阴影   一段明明打出来了，但是就是没有效果的鼠标悬浮、按压阴影（那就是没有用 的代码，哈哈。
void MainWindow::initButtonShadow(void)
{
    num0_shadow = new QGraphicsDropShadowEffect();
    num1_shadow = new QGraphicsDropShadowEffect();
    num2_shadow = new QGraphicsDropShadowEffect();
    num3_shadow = new QGraphicsDropShadowEffect();
    num4_shadow = new QGraphicsDropShadowEffect();
    num5_shadow = new QGraphicsDropShadowEffect();
    num6_shadow = new QGraphicsDropShadowEffect();
    num7_shadow = new QGraphicsDropShadowEffect();
    num8_shadow = new QGraphicsDropShadowEffect();
    num9_shadow = new QGraphicsDropShadowEffect();

    plus_shadow = new QGraphicsDropShadowEffect();
    minus_shadow = new QGraphicsDropShadowEffect();
    mutiply_shadow = new QGraphicsDropShadowEffect();
    divide_shadow = new QGraphicsDropShadowEffect();
    dot_shadow = new QGraphicsDropShadowEffect();
    clear_shadow = new QGraphicsDropShadowEffect();
    left_parenthesis_shadow = new QGraphicsDropShadowEffect();
    right_parenthesis_shadow = new QGraphicsDropShadowEffect();
    logic_and_shadow = new QGraphicsDropShadowEffect();
    parallel_shadow = new QGraphicsDropShadowEffect();
    none_shadow = new QGraphicsDropShadowEffect();

    QGraphicsDropShadowEffect * allShadow[] = {
        num0_shadow,num1_shadow,num2_shadow,num3_shadow,num4_shadow,num5_shadow,num6_shadow,
        num7_shadow,num8_shadow,num9_shadow,plus_shadow,minus_shadow,mutiply_shadow,divide_shadow,
        dot_shadow,clear_shadow,backspace_shadow,left_parenthesis_shadow,right_parenthesis_shadow
        ,parallel_shadow,none_shadow,logic_and_shadow};
    for(int i=0;i<25;++i)
    {
        allShadow[i]->setBlurRadius(14);
        allShadow[i]->setOffset(-1,1);
        allShadow[i]->setColor(Qt::gray);
        allShadow[i]->setEnabled(false);
    }
}

void MainWindow::addNumButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(true);
    button->setStyleSheet(
        "border:1px groove rgb(220,220,220);"
        "background-color:rgb(193,193,193);"
    );
}
void MainWindow::removeNumButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(false);
    button->setStyleSheet("border:1px groove rgb(220,220,220);background-color:rgb(243,243,243);");
}
void MainWindow::addSignButtonEffect(QPushButton *button, QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(true);
    button->setStyleSheet(
        "border:1px groove rgb(220,220,220);"
        "background-color:rgb(170,170,170);"
    );
}

void MainWindow::removeSignButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(false);
    button->setStyleSheet("border:1px groove rgb(220,220,220);background-color:rgb(235,235,235);");
}

void MainWindow::installButtonEventFilter(void)
{
    ui->num0->installEventFilter(this);
    ui->num1->installEventFilter(this);
    ui->num2->installEventFilter(this);
    ui->num3->installEventFilter(this);
    ui->num4->installEventFilter(this);
    ui->num5->installEventFilter(this);
    ui->num6->installEventFilter(this);
    ui->num7->installEventFilter(this);
    ui->num8->installEventFilter(this);
    ui->num9->installEventFilter(this);
    ui->plus->installEventFilter(this);
    ui->minus->installEventFilter(this);
    ui->mutiply->installEventFilter(this);
    ui->divide->installEventFilter(this);
    ui->dot->installEventFilter(this);
    ui->clear->installEventFilter(this);
    ui->backspace->installEventFilter(this);
    ui->left_parenthesis->installEventFilter(this);
    ui->right_parenthesis->installEventFilter(this);
    ui->logic_and->installEventFilter(this);
    ui->parallel->installEventFilter(this);
    ui->none->installEventFilter(this);
}



bool MainWindow::eventFilter(QObject *object,QEvent *event)
{
    if(event->type() == QEvent::HoverEnter)
    {
        if(object == ui->num0)
            addNumButtonEffect(ui->num0,num0_shadow);
        else if(object == ui->num1)
            addNumButtonEffect(ui->num1,num1_shadow);
        else if(object == ui->num2)
            addNumButtonEffect(ui->num2,num2_shadow);
        else if(object == ui->num3)
            addNumButtonEffect(ui->num3,num3_shadow);
        else if(object == ui->num4)
            addNumButtonEffect(ui->num4,num4_shadow);
        else if(object == ui->num5)
            addNumButtonEffect(ui->num5,num5_shadow);
        else if(object == ui->num6)
            addNumButtonEffect(ui->num6,num6_shadow);
        else if(object == ui->num7)
            addNumButtonEffect(ui->num7,num7_shadow);
        else if(object == ui->num8)
            addNumButtonEffect(ui->num8,num8_shadow);
        else if(object == ui->num9)
            addNumButtonEffect(ui->num9,num9_shadow);
        else if(object == ui->plus)
            addSignButtonEffect(ui->plus,plus_shadow);
        else if(object == ui->minus)
            addSignButtonEffect(ui->minus,minus_shadow);
        else if(object == ui->mutiply)
            addSignButtonEffect(ui->mutiply,mutiply_shadow);
        else if(object == ui->divide)
            addSignButtonEffect(ui->divide,divide_shadow);

        else if(object == ui->dot)
            addSignButtonEffect(ui->dot,dot_shadow);
        else if(object == ui->clear)
            addSignButtonEffect(ui->clear,clear_shadow);
        else if(object == ui->backspace)
            addSignButtonEffect(ui->backspace,backspace_shadow);
    }
    else if(event->type() == QEvent::HoverLeave)
    {
        if(object == ui->num0)
            removeNumButtonEffect(ui->num0,num0_shadow);
        else if(object == ui->num1)
            removeNumButtonEffect(ui->num1,num1_shadow);
        else if(object == ui->num2)
            removeNumButtonEffect(ui->num2,num2_shadow);
        else if(object == ui->num3)
            removeNumButtonEffect(ui->num3,num3_shadow);
        else if(object == ui->num4)
            removeNumButtonEffect(ui->num4,num4_shadow);
        else if(object == ui->num5)
            removeNumButtonEffect(ui->num5,num5_shadow);
        else if(object == ui->num6)
            removeNumButtonEffect(ui->num6,num6_shadow);
        else if(object == ui->num7)
            removeNumButtonEffect(ui->num7,num7_shadow);
        else if(object == ui->num8)
            removeNumButtonEffect(ui->num8,num8_shadow);
        else if(object == ui->num9)
            removeNumButtonEffect(ui->num9,num9_shadow);
        else if(object == ui->plus)
            removeSignButtonEffect(ui->plus,plus_shadow);
        else if(object == ui->minus)
            removeSignButtonEffect(ui->minus,minus_shadow);
        else if(object == ui->mutiply)
            removeSignButtonEffect(ui->mutiply,mutiply_shadow);
        else if(object == ui->divide)
            removeSignButtonEffect(ui->divide,divide_shadow);
        else if(object == ui->dot)
            removeSignButtonEffect(ui->dot,dot_shadow);
        else if(object == ui->clear)
            removeSignButtonEffect(ui->clear,clear_shadow);
        else if(object == ui->logic_and)
            removeSignButtonEffect(ui->logic_and,logic_and_shadow);
        else if(object == ui->parallel)
            removeSignButtonEffect(ui->parallel,parallel_shadow);
        else if(object == ui->none)
            removeSignButtonEffect(ui->none,none_shadow);
        else if(object == ui->left_parenthesis)
            removeSignButtonEffect(ui->left_parenthesis,left_parenthesis_shadow);
        else if(object == ui->right_parenthesis)
            removeSignButtonEffect(ui->right_parenthesis,right_parenthesis_shadow);
        else if(object == ui->backspace)
            removeSignButtonEffect(ui->backspace,backspace_shadow);
    }
}

void MainWindow::setButtonShadow(void)
{
    ui->num0->setGraphicsEffect(num0_shadow);
    ui->num1->setGraphicsEffect(num1_shadow);
    ui->num2->setGraphicsEffect(num2_shadow);
    ui->num3->setGraphicsEffect(num3_shadow);
    ui->num4->setGraphicsEffect(num4_shadow);
    ui->num5->setGraphicsEffect(num5_shadow);
    ui->num6->setGraphicsEffect(num6_shadow);
    ui->num7->setGraphicsEffect(num7_shadow);
    ui->num8->setGraphicsEffect(num8_shadow);
    ui->num9->setGraphicsEffect(num9_shadow);

    ui->plus->setGraphicsEffect(plus_shadow);
    ui->minus->setGraphicsEffect(minus_shadow);
    ui->mutiply->setGraphicsEffect(mutiply_shadow);
    ui->divide->setGraphicsEffect(divide_shadow);
    ui->logic_and->setGraphicsEffect(logic_and_shadow);
    ui->parallel->setGraphicsEffect(parallel_shadow);
    ui->none->setGraphicsEffect(none_shadow);
    ui->dot->setGraphicsEffect(dot_shadow);
    ui->clear->setGraphicsEffect(clear_shadow);
    ui->left_parenthesis->setGraphicsEffect(left_parenthesis_shadow);
    ui->right_parenthesis->setGraphicsEffect(right_parenthesis_shadow);
    ui->backspace->setGraphicsEffect(backspace_shadow);
}

//一段正在试图做键盘效果但是失败了的代码 哈哈。

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//    switch (event->key())
//    {
//    case Qt::Key_0:
//        addNumButtonEffect(ui->num0,num0_shadow);
//        on_num0_clicked();
//        break;
//    case Qt::Key_1:
//        addNumButtonEffect(ui->num1,num1_shadow);
//        on_num1_clicked();
//        break;

//    case Qt::Key_2:
//        addNumButtonEffect(ui->num2,num2_shadow);
//        on_num2_clicked();
//        break;

//    case Qt::Key_3:
//        addNumButtonEffect(ui->num3,num3_shadow);
//        on_num3_clicked();
//        break;

//    case Qt::Key_4:
//        addNumButtonEffect(ui->num4,num4_shadow);
//        on_num4_clicked();
//        break;

//    case Qt::Key_5:
//        addNumButtonEffect(ui->num5,num5_shadow);
//        on_num5_clicked();
//        break;

//    case Qt::Key_6:
//        addNumButtonEffect(ui->num6,num6_shadow);
//        on_num6_clicked();
//        break;

//    case Qt::Key_7:
//        addNumButtonEffect(ui->num7,num7_shadow);
//        on_num7_clicked();
//        break;

//    case Qt::Key_8:
//        addNumButtonEffect(ui->num8,num8_shadow);
//        on_num8_clicked();
//        break;

//    case Qt::Key_9:
//        addNumButtonEffect(ui->num9,num9_shadow);
//        on_num9_clicked();
//        break;

//    case Qt::Key_Plus:
//        addSignButtonEffect(ui->plus,plus_shadow);
//        on_plus_clicked();
//        break;

//    case Qt::Key_Minus:
//        addSignButtonEffect(ui->minus,minus_shadow);
//        on_minus_clicked();
//        break;

//    case Qt::Key_Asterisk:
//        addSignButtonEffect(ui->mutiply,mutiply_shadow);
//        on_mutiply_clicked();
//        break;

//    case Qt::Key_Slash:
//        addSignButtonEffect(ui->divide,divide_shadow);
//        on_divide_clicked();
//        break;


//    case Qt::Key_Backspace:
//        addSignButtonEffect(ui->backspace,backspace_shadow);
//        if(ui->box->text() != "0")
//        {
//            ui->box->setReadOnly(false);
//            if(ui->box->text().size() == 1)
//                ui->box->setText("0");
//            else
//                ui->box->setText(ui->box->text().mid(0,ui->box->text().size()-1));
//            ui->box->setReadOnly(true);
//        }
//        break;

//    case Qt::Key_Period:
//        addSignButtonEffect(ui->dot,dot_shadow);
//        on_dot_clicked();
//        break;
//    }
//}

//void MainWindow::keyReleaseEvent(QKeyEvent *event)
//{
//    switch (event->key())
//    {
//        case Qt::Key_0:
//        case Qt::Key_1:
//        case Qt::Key_2:
//        case Qt::Key_3:
//        case Qt::Key_4:
//        case Qt::Key_5:
//        case Qt::Key_6:
//        case Qt::Key_7:
//        case Qt::Key_8:
//        case Qt::Key_9:
//        case Qt::Key_Plus:
//        case Qt::Key_Minus:
//        case Qt::Key_Asterisk:
//        case Qt::Key_Slash:
//        case Qt::Key_Backspace:
//        case Qt::Key_Period:
//            removeNumButtonEffect(ui->num0,num0_shadow);
//            removeNumButtonEffect(ui->num1,num1_shadow);
//            removeNumButtonEffect(ui->num2,num2_shadow);
//            removeNumButtonEffect(ui->num3,num3_shadow);
//            removeNumButtonEffect(ui->num4,num4_shadow);
//            removeNumButtonEffect(ui->num5,num5_shadow);
//            removeNumButtonEffect(ui->num6,num6_shadow);
//            removeNumButtonEffect(ui->num7,num7_shadow);
//            removeNumButtonEffect(ui->num8,num8_shadow);
//            removeNumButtonEffect(ui->num9,num9_shadow);
//            removeSignButtonEffect(ui->plus,plus_shadow);
//            removeSignButtonEffect(ui->minus,minus_shadow);
//            removeSignButtonEffect(ui->mutiply,mutiply_shadow);
//            removeSignButtonEffect(ui->divide,divide_shadow);
//            removeSignButtonEffect(ui->backspace,backspace_shadow);
//            removeSignButtonEffect(ui->dot,dot_shadow);
//            break;
//    }
//}


