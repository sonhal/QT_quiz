#include "mainwindow.h"
#include "ui_mainwindow.h"


void quiz(QVector<QString> q){
    int i = 0;
    for(i < q.size(); i++;){


    }
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->answer_1_button, SIGNAL(clicked(bool)),this, SLOT(quiz_button_pressed(bool)));
    connect(ui->answer_2_button, SIGNAL(clicked(bool)),this, SLOT(quiz_button_pressed(bool)));
    connect(ui->answer_3_button, SIGNAL(clicked(bool)),this, SLOT(quiz_button_pressed(bool)));

    connect(ui->option_history, SIGNAL(clicked(bool)),this, SLOT(option_button_pressed(bool)));
    connect(ui->option_nature, SIGNAL(clicked(bool)),this, SLOT(option_button_pressed(bool)));
    connect(ui->option_sports, SIGNAL(clicked(bool)),this, SLOT(option_button_pressed(bool)));

}

void MainWindow::quiz_button_pressed(bool){
    counter++;
    if(counter < questions.size()){
    ui->question_text->setText(questions[counter]);
    ui->question_options->setText(questions_options[counter]);
    }
    else{
        ui->stackedWidget->setCurrentIndex(1);
        ui->result_username->setText(username);
        ui->result_score->setText(calc_score());
    }

}

void MainWindow::option_button_pressed(bool){


    ui->stackedWidget->setCurrentIndex(5);

    switch(option){

    case 1 :
        questions = questions_history;
        questions_options = questions_history_options;
        fasit = fasit_history;

    case 2 :
        questions = questions_history;


    case 3 :
    questions = questions_history;

     }
     ans_list = questions_options[counter].split(" ",QString::SkipEmptyParts);
     vect_list = ans_list.toVector();
     ui->question_text->setText(questions[counter]);
     ui->question_options->setText(questions_options[counter]);
     ui->answer_1_button->setText(vect_list[0]);
     ui->answer_2_button->setText(vect_list[1]);
     ui->answer_3_button->setText(vect_list[2]);
}

QString MainWindow::calc_score(){
    int score = 0;
    for(int i=0; i < fasit.size(); i++){

        if(answers[i] == fasit[i]){
            score++;
        }
    }
    QString s = QString::number(score);

    QFile file("scoreb.txt");

    if (!file.exists()) {

    }
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        return s;
    }



    QTextStream out(&file);
        out << username << "," << s;



    return s;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    username = ui->username->text();

 ui->stackedWidget->setCurrentIndex(2);
 ui->menu_username->setText(username);

}




void MainWindow::on_quiz_button_clicked()
{

    ui->stackedWidget->setCurrentIndex(4);


}


void MainWindow::on_answer_1_button_clicked()
{
    answers.append("1");

}
void MainWindow::on_answer_2_button_clicked()
{
    answers.append("2");

}
void MainWindow::on_answer_3_button_clicked()
{
    answers.append("3");

}





void MainWindow::on_option_history_clicked()
{
    option = 1;
}

void MainWindow::on_option_nature_clicked()
{
    option = 2;
}

void MainWindow::on_option_sports_clicked()
{
    option = 3;
}

void MainWindow::on_scoreboard_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QFile file("scoreb.txt");

    if (!file.exists()) {
     ui->score_label_1->setText("buu");
    }
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        return;
    }

    QTextStream in(&file);
       while (!in.atEnd()) {
           scores.append(in.readLine());
       }

       score_2d.resize(2);
       score_2d[0].resize(2);
       ui->score_label_1->setText(scores[0]);
      if(scores.count() > 0){
     for(int i = 0; i < scores.size(); i++){
         QVector<QString> holder;
         QStringList list1 = scores[i].split(",");
         holder = list1.toVector();
         ui->score_label_2->setText(holder[0]);

         score_2d[i][0].append(holder[0]);
         score_2d[i][1].append(holder[1]);
     }
    // qSort(score_2d);
     //ui->score_label_3->setText(score_2d[0][0]);
       }



}

void MainWindow::on_result_gotomenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
