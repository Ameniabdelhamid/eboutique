#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <time.h>
#include <sys/time.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "marque1.h"
#include"consultepro.h"
   char text[20];
char welcome [20];
char welcome1 [20];
  char prixT[20];
  char imageT[20];
   char marqueT[20];
  GtkWidget *window;
  GtkWidget *consProWindow;
  GtkWidget *fixed;
gchar *sUtf8;
  GtkWidget *btn1;
  GtkWidget *btn2;
  GtkWidget *conxImage;
  GtkWidget *InscritImage;
  GtkWidget *CoinIm;
   GtkWidget *SlidIm;
  GtkWidget *RechercheText;
  GtkWidget *RechercheLabel;
  GtkWidget *MarqueLabel;
   GtkWidget *MarqueImage1;
   GtkWidget *MarqueImage2;
   GtkWidget *MarqueImage3;
   GtkWidget *MarqueImage4;
   GtkWidget *nomLabel;
GtkWidget *prenomLabel;
GtkWidget *adresseLabel;
GtkWidget *code_pLabel;
GtkWidget *villeLabel;
GtkWidget *passwordLabel;
GtkWidget *confirmPasswordLabel;
GtkWidget *telLabel;
GtkWidget *emailLabel;

GtkWidget * InscritWindow;
GtkWidget * window;
GtkWidget *nomText;
GtkWidget *prenomText;
GtkWidget *adresseText;
GtkWidget *passwordText;
GtkWidget *confirmPasswordText;
GtkWidget *code_pText;
GtkWidget *telText;
GtkWidget *emailText;
GtkWidget *villeText;

GtkWidget *nomImage;
GtkWidget *prenomImage;
GtkWidget *adresseImage;
GtkWidget *passImage;
GtkWidget *confirmImage;
GtkWidget *villeImage;
GtkWidget *telImage;
GtkWidget *emailImage;
GtkWidget *code_pImage;
   GdkColor color;
   GdkColor colorB;
   char *idmar[50];
          char *idus;
   char text[20];
char welcome [20];
char welcome1 [20];
  char nomUser[20];
  char prenomUser[20];
   void insertion_msg22(gpointer data);
void ConsulteProduit(int argc, char **argv)
{
    GtkWidget* window;
    GtkWidget* box;
    GtkWidget *scrollbar;
    int i;

 gtk_init(&argc,&argv);

 consProWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(consProWindow), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW (consProWindow), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW(consProWindow), 1350, 700);
  gtk_window_set_position(GTK_WINDOW(consProWindow),GTK_WIN_POS_CENTER);
  //g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(onDestroyOffre),NULL);

    scrollbar = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(consProWindow),scrollbar);

    box=gtk_vbox_new(FALSE,5);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollbar), box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollbar), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);


fixed = gtk_fixed_new ();
  gtk_widget_show (fixed);
  gtk_container_add (GTK_CONTAINER (box), fixed);


 g_signal_connect(G_OBJECT(consProWindow),"destroy",G_CALLBACK(onDestroyConP),NULL);




	//RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(btn1), GTK_STATE_NORMAL, &colorB);

  GtkWidget  * ComLabel1 = gtk_label_new("Toujours plus de nouveaut�s sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveaut�s sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel1), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel1,850,250);
      GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveaut�s sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveaut�s sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);

 /* tout les parametre des images */

       SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);

       GtkWidget * ForLabel = gtk_label_new("");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"200\" foreground=\"#920391\"><b>Consulter Produits</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ForLabel), sUtf8);
    g_free(sUtf8);
    nomLabel = gtk_label_new("Libell�");
     sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Libell�</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( nomLabel), sUtf8);
    g_free(sUtf8);
    prenomLabel  = gtk_label_new("Prix");
   sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Prix</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( prenomLabel), sUtf8);
    g_free(sUtf8);

   emailLabel =gtk_label_new("Image");
   sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Image</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( emailLabel), sUtf8);
    g_free(sUtf8);
     adresseLabel = gtk_label_new("Marque ");
        sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Marque</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( adresseLabel), sUtf8);
    g_free(sUtf8);

    gtk_fixed_put(GTK_FIXED(fixed),ForLabel,30,400);
    gtk_fixed_put(GTK_FIXED(fixed),nomLabel,130,450);
    gtk_fixed_put(GTK_FIXED(fixed),prenomLabel,330,450);
    gtk_fixed_put(GTK_FIXED(fixed),emailLabel,530,450);
    gtk_fixed_put(GTK_FIXED(fixed),adresseLabel,730,450);


/*Button*/

    GtkWidget * BackButton;


BackButton = gtk_button_new_with_label("Retour");


  gtk_fixed_put(GTK_FIXED(fixed),BackButton,1250,600);

     g_signal_connect(G_OBJECT(consProWindow),"destroy",G_CALLBACK(onDestroyConP),NULL);
  g_signal_connect (BackButton,"button_press_event",G_CALLBACK (onClickConP), 1);


MYSQL *mysql;
    //Initialisation de MySQL
        mysql = mysql_init(NULL);
    //Options de connexion
        mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion r�ussie...
        if(mysql_real_connect(mysql,"localhost","root","","eboutique",0,NULL,0))
         {
            char req[1000];

            mysql_query(mysql,"select  * from produits");

            MYSQL_RES *result = NULL;
            MYSQL_ROW row;

 int y =450;
            int x=130;
            int ix =30;
            int iy =200;

              //On met le jeu de r�sultat dans le pointeur result
            result = mysql_use_result(mysql);

        //On r�cup�re le nombre de champs


        //Tant qu'il y a encore un r�sultat ...
        while ((row = mysql_fetch_row(result)))
        {
            //On d�clare un pointeur long non sign� pour y stocker la taille des valeurs
            unsigned long *lengths;

            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);
               char text[50];



               sprintf(text,"%s",row[1]);
             GtkWidget *nomLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),nomLibele,x,y+50);
x=x+200;


             sprintf(text,"%s",row[3]);
             GtkWidget *prenomLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),prenomLibele,x,y+50);
x=x+200;


     sprintf(text,"%s",row[4]);
             GtkWidget *emailLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),emailLibele,x,y+50);
            x=x+200;

             sprintf(text,"%s",row[5]);
             GtkWidget *adresseLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),adresseLibele,x,y+50);

x=x-600;
y=y+50;
            printf("\n");
        }

            mysql_free_result(result);
            mysql_close(mysql);
           }
             else
              {
                  printf("Une erreur s'est produite lors de la connexion � la BDD!");
              }


//RGB(246^2,249^2,252^2)
	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(consProWindow), GTK_STATE_NORMAL, &color);


    gtk_widget_show_all(consProWindow);

    gtk_main();

    return 0;
}
void onDestroyConP(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}

static gboolean onClickConP( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {
        gtk_widget_hide(consProWindow);

        AdminG(argc,argv,text,idus,nomUser,prenomUser);

    }


}

