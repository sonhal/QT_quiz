#include "mainwindow.h"
#include "ui_mainwindow.h"



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
    button_counter + 3;

    if(counter < questions.size()){
        ans_list = questions_options[counter].split(" ",QString::SkipEmptyParts);
        vect_list = ans_list.toVector();

    ui->question_text->setText(questions[counter]);
    ui->question_options->setText(questions_options[counter]);

    ui->answer_1_button->setText(vect_list[0 + button_counter]);
    ui->answer_2_button->setText(vect_list[1] + button_counter);
    ui->answer_3_button->setText(vect_list[2] + button_counter);
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
       break;
    case 2 :
        questions = questions_nature;
        questions_options = questions_nature_options;
        fasit = fasit_nature;
       break;
    case 3 :
    questions = questions_sports;
    questions_options = questions_sports_options;
    fasit = fasit_sports;
     break;
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

    QFile file("scored.txt");

    if (!file.exists()) {

    }
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)){
        return s;
    }



    QTextStream out(&file);
        out << username << "," << s << "\n";
        out.flush();



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
    QFile file("scored.txt");

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




      if(scores.count() > 0){

          score_2d.resize(scores.count());
          for(int i = 0; i < scores.count(); i++){
            score_2d[i].resize(2);
          }


     for(int i = 0; i < scores.size(); i++){
         QVector<QString> holder;
         QStringList list1 = scores[i].split(",");
         holder = list1.toVector();


         score_2d[i][0].append(holder[0]);
         score_2d[i][1].append(holder[1]);
     }

     top_score();
       }



}


void MainWindow::top_score(){
    QVector< QVector<QString> > helper = score_2d;
    QString v;
    v = QString::number(helper.count());


     for(int j = helper.size() -1; j >= 1; j--){

         for(int i = helper.size() -1 ; i >= 1; i--){

             if(helper[i][1] > helper[i - 1][1]){
                 QVector <QVector<QString> > tmp;
                 tmp.resize(2);
                 tmp[0].resize(2);
                 tmp[0] = helper[i];
                 helper[i] = helper[i - 1];
                 helper[i - 1] = tmp[0];

             }

         }


    }



     switch(helper.size() -1){

     case 1 :
         ui->score_label_1->setText(helper[0][0] + " score: " + helper[0][1]);

     case 2 :
         ui->score_label_1->setText(helper[0][0] + " score: " + helper[0][1]);
         ui->score_label_2->setText(helper[1][0] + " score: " + helper[1][1]);

     case 3 :
         ui->score_label_1->setText(helper[0][0] + " score: " + helper[0][1]);
         ui->score_label_2->setText(helper[1][0] + " score: " + helper[1][1]);
         ui->score_label_3->setText(helper[2][0] + " score: " + helper[2][1]);


     case 4 :
         ui->score_label_1->setText(helper[0][0] + " score: " + helper[0][1]);
         ui->score_label_2->setText(helper[1][0] + " score: " + helper[1][1]);
         ui->score_label_3->setText(helper[2][0] + " score: " + helper[2][1]);
         ui->score_label_4->setText(helper[3][0] + " score: " + helper[3][1]);


     default :
         ui->score_label_1->setText(helper[0][0] + " score: " + helper[0][1]);
         ui->score_label_2->setText(helper[1][0] + " score: " + helper[1][1]);
         ui->score_label_3->setText(helper[2][0] + " score: " + helper[2][1]);
         ui->score_label_4->setText(helper[3][0] + " score: " + helper[3][1]);
         ui->score_label_5->setText(helper[4][0] + " score: " + helper[4][1]);
}

}

void MainWindow::on_result_gotomenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    counter = 0;
    button_counter = 0;
    questions.clear();
    questions_options.clear();
    answers.clear();
    fasit.clear();
    option = 0;
}



void MainWindow::on_scoreboard_gotomenu_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    scores.clear();
    score_2d.clear();
}
