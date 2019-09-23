#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include <string.h>
#include "index.h"
#include "connexion.h"
GtkWidget *ConnectWindow;

GtkWidget *BackButton;
GtkWidget *confirmButton;
GtkWidget *resetButton;

GtkWidget *fixed;
gchar * sUtf8;

GtkWidget *passwordLabel;

GtkWidget *emailLabel;
GtkWidget *passwordText;
GtkWidget *emailText;



GtkWidget *passImage;
GtkWidget *emailImage;
GtkWidget *SlidIm;
void error_auth(gpointer data);
void Connexion(int argc,char **argv)
{

/* tout les parametres de mon fenetre signupWindow" */
 ConnectWindow= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(ConnectWindow), "CoinMakeup Connexion");
gtk_window_set_icon_from_file(GTK_WINDOW (ConnectWindow), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW(ConnectWindow), 1350, 700);
  gtk_window_set_position(GTK_WINDOW(ConnectWindow), GTK_WIN_POS_CENTER);
    g_signal_connect(G_OBJECT(ConnectWindow),"destroy",G_CALLBACK(onDestroyConnect),NULL);
fixed = gtk_fixed_new();
gtk_container_add(GTK_CONTAINER(ConnectWindow),fixed);
  SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
  GdkColor color;
	//RGB(246^2,249^2,252^2)
	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(ConnectWindow), GTK_STATE_NORMAL, &color);
     /*label properties */

     GtkWidget * ForLabel = gtk_label_new("Déja enregistré?");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"200\" foreground=\"#920391\"><b>Déja enregistré?</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ForLabel), sUtf8);
    g_free(sUtf8);

   emailLabel =gtk_label_new("Email");
    passwordLabel = gtk_label_new("Mot De passe");


    emailImage = gtk_image_new_from_file("images/email.png");
    passImage = gtk_image_new_from_file("images/pass.png");

/*Button*/
confirmButton = gtk_button_new_with_label("Identifier-vous");
BackButton = gtk_button_new_with_label("Retour");
  g_signal_connect (confirmButton,"button_press_event",G_CALLBACK (onClickConnect), 1);
  g_signal_connect (BackButton,"button_press_event",G_CALLBACK (onClickConnect), 2);

    /* entry properties */



  emailText = gtk_entry_new ();
    passwordText = gtk_entry_new ();


gtk_entry_set_visibility (GTK_ENTRY (passwordText),FALSE);

    gtk_entry_set_max_length (GTK_ENTRY (emailText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (passwordText), 50);

    /* fixed properties */
    gtk_fixed_put(GTK_FIXED(fixed),ForLabel,55,400);
    gtk_fixed_put(GTK_FIXED(fixed),emailLabel,65,490);
    gtk_fixed_put(GTK_FIXED(fixed),passwordLabel,65,530);



    gtk_fixed_put(GTK_FIXED(fixed),emailImage,35,490);
    gtk_fixed_put(GTK_FIXED(fixed),passImage,35,525);


    gtk_fixed_put(GTK_FIXED(fixed),emailText,250,490);
    gtk_fixed_put(GTK_FIXED(fixed),passwordText,250,525);


    gtk_fixed_put(GTK_FIXED(fixed),confirmButton,220,600);
  gtk_fixed_put(GTK_FIXED(fixed),BackButton,320,600);
GdkColor colorB;
	//RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(confirmButton), GTK_STATE_NORMAL, &colorB);
    gtk_widget_modify_bg(GTK_WIDGET(BackButton), GTK_STATE_NORMAL, &colorB);
    gtk_container_add(GTK_CONTAINER(ConnectWindow),fixed);

  GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);
    gtk_widget_show_all(ConnectWindow);
    gtk_widget_show(ConnectWindow);
    }

    void onDestroyConnect(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}
static gboolean onClickConnect( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
    if(data==1)
 { printf("Connect Button \n");

        gchar *email,*pass;
        email = gtk_entry_get_text (GTK_ENTRY (emailText));
        pass = gtk_entry_get_text (GTK_ENTRY (passwordText));

        printf ("login :%s password :%s \n",email,pass);

    //Déclaration du pointeur de structure de type MYSQL
        MYSQL *mysql;
    //Initialisation de MySQL
        mysql = mysql_init(NULL);
    //Options de connexion
        mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion réussie...
        if(mysql_real_connect(mysql,"localhost","root","","eboutique",0,NULL,0))
         {
            char req[1000];

            sprintf(req,"select iduser,email,nom,prenom,type from user where email ='%s' and password = '%s' ",email,pass);

            mysql_query(mysql,req);
            MYSQL_RES *result = NULL;
            MYSQL_ROW row;

            result = mysql_use_result(mysql);

            row = mysql_fetch_row(result);

            int x = mysql_num_rows(result);

              if( x == 1)
              {
                  if(row[4]=="client")
                      {

                          gtk_widget_hide(ConnectWindow);
                  Client(argc,argv,row[1],row[0],row[2],row[3]);
                      }
else
{gtk_widget_hide(ConnectWindow);
                  AdminMagasin(argc,argv,row[1],row[0],row[2],row[3]);
}


              }
              else
                error_auth(ConnectWindow);


            mysql_free_result(result);
           //Fermeture de MySQL
            mysql_close(mysql);
           }
             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }

      }

    if(data == 2)
    {
        gtk_widget_hide(ConnectWindow);
       IndexPage1(argc,argv);

    }

}
void error_auth(gpointer data)
{
    GtkWidget *pAbout;
    gchar *info ="Erreur d'authentication \n email ou mot de passe incorrect";

    pAbout = gtk_message_dialog_new(GTK_WINDOW(data),
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_ERROR,
                                    GTK_BUTTONS_CLOSE,
                                    info
                                    );
    gtk_dialog_run(GTK_DIALOG(pAbout));

    gtk_widget_destroy(pAbout);
}
