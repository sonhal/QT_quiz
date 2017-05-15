#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString calc_score();



private slots:
    void on_pushButton_clicked();
    void option_button_pressed(bool);
    void quiz_button_pressed(bool);


    void on_quiz_button_clicked();

    void on_answer_1_button_clicked();
    void on_answer_2_button_clicked();
    void on_answer_3_button_clicked();

    void on_option_history_clicked();

    void on_option_nature_clicked();

    void on_option_sports_clicked();

private:
    int option;
    QString username = "hih";
    int counter = 0;
    QVector<QString> questions = {"Who killed Arbaham Lincon? 1.J 2.asd 3. asd", "Who is he? 1. 2. 3. "};
    QVector<QString> questions_options;
    QVector<QString> questions_history = {"World War I began in which year?", "Adolf Hitler was born in which country?","John F. Kennedy was assassinated in","Which general famously stated 'I shall return'?","American involvement in the Korean War took place in which decade?","The Battle of Hastings in 1066 was fought in which country?","The Magna Carta was published by the King of which country?","The first successful printing press was developed by this man.","The first successful printing press was developed by this man.","The disease that ravaged and killed a third of Europe's population in the 14th century is known as","The Hundred Years War was fought between what two countries?"};
    QVector<QString> questions_history_options = {"1923 1936 1938","France Germany Austria","Austin Dallas Paris","Bull-Halsey George-Patton Douglas-MacArthur","1970s 1950s 1920s", "France Russia England", "France Austria England","Johannes-Gutenburg Benjamin-Franklin Si-Isaac-Newton","The-Black-Plague Smallpox The-Bubonic-Plague","Italy-and-Carthage England-and-Germany France-and-England"};
    QVector<QString> fasit = {"1","2"};
    QVector<QString> fasit_history = {"3","3","2","2","1","2","1","2","1","2"};
    QVector<QString> answers;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
