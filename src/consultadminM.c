#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "consultadminM.h"

  GtkWidget * consMWindow;
  GtkWidget *fixed;
gchar *sUtf8;
  GtkWidget *btn1;
  GtkWidget *btn2;
    GtkWidget *btn3;
  GtkWidget *btn4;
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
   GdkColor color;
   GdkColor colorB;



   const gchar *nom,*image;
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


      char *idus;
   char text[20];
char welcome [20];
char welcome1 [20];
  char nomUser[20];
  char prenomUser[20];
  GtkWidget *nomImage;
GtkWidget *imageText;
 GtkWidget *  nomText;
    const gchar *nom,*image;
 void insertion_msg3(gpointer data);
   void ConsultAdminM(int argc, char **argv) {
       gtk_init(&argc, &argv);

       /* tout les parametres de mon fenetre authWindow" */
    consMWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW( consMWindow), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW ( consMWindow), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW( consMWindow), 1350, 700);
  gtk_window_set_position(GTK_WINDOW( consMWindow), GTK_WIN_POS_CENTER);
  fixed = gtk_fixed_new();
  	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(consMWindow), GTK_STATE_NORMAL, &color);
  gtk_container_add(GTK_CONTAINER( consMWindow), fixed);
         SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
      GtkWidget * RechImage = gtk_image_new_from_file("images/re.png");
      gtk_fixed_put(GTK_FIXED(fixed),RechImage,285,37);

     GtkWidget * ForLabel = gtk_label_new("");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"200\" foreground=\"#920391\"><b>Consulter Admin Magasin</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ForLabel), sUtf8);
    g_free(sUtf8);
    nomLabel = gtk_label_new("Nom  ");
     sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Nom</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( nomLabel), sUtf8);
    g_free(sUtf8);
    prenomLabel  = gtk_label_new("Prénom");
   sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Prénom</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( prenomLabel), sUtf8);
    g_free(sUtf8);

   emailLabel =gtk_label_new("Email  ");
   sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Email</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( emailLabel), sUtf8);
    g_free(sUtf8);
     adresseLabel = gtk_label_new("Adresse  ");
        sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Adresse</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( adresseLabel), sUtf8);
    g_free(sUtf8);
    villeLabel = gtk_label_new("Ville  ");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Ville</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( villeLabel), sUtf8);
    g_free(sUtf8);
   code_pLabel =gtk_label_new("Code postal");
      sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"40\" foreground=\"#920391\"><b>Code postal</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( code_pLabel), sUtf8);
    g_free(sUtf8);
    telLabel = gtk_label_new("Téléphone  ");
     sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Téléphone</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( telLabel), sUtf8);
    g_free(sUtf8);

    GtkWidget *effLabel = gtk_label_new("Effacer");

     sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Effacer</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( effLabel), sUtf8);
    g_free(sUtf8);
    GtkWidget *upLabel = gtk_label_new("Modifier");

     sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"80\" foreground=\"#920391\"><b>Modifier</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( upLabel), sUtf8);
    g_free(sUtf8);
    gtk_fixed_put(GTK_FIXED(fixed),ForLabel,30,400);
    gtk_fixed_put(GTK_FIXED(fixed),nomLabel,130,450);
    gtk_fixed_put(GTK_FIXED(fixed),prenomLabel,230,450);
    gtk_fixed_put(GTK_FIXED(fixed),emailLabel,330,450);
    gtk_fixed_put(GTK_FIXED(fixed),adresseLabel,530,450);
    gtk_fixed_put(GTK_FIXED(fixed),villeLabel,630,450);
    gtk_fixed_put(GTK_FIXED(fixed),code_pLabel,730,450);
    gtk_fixed_put(GTK_FIXED(fixed),telLabel,930,450);
     gtk_fixed_put(GTK_FIXED(fixed),upLabel,1030,450);
      gtk_fixed_put(GTK_FIXED(fixed),effLabel,1130,450);

/*Button*/
  GtkWidget *modButton;
    GtkWidget * BackButton;
     GtkWidget * effButton;
effButton = gtk_button_new_with_label("Effacer");
BackButton = gtk_button_new_with_label("Retour");
modButton = gtk_button_new_with_label("Modifier");

  gtk_fixed_put(GTK_FIXED(fixed),BackButton,1250,600);

     g_signal_connect(G_OBJECT(consMWindow),"destroy",G_CALLBACK(onDestroyConM),NULL);
  g_signal_connect (effButton,"button_press_event",G_CALLBACK (onClickConM), 1);
  g_signal_connect (BackButton,"button_press_event",G_CALLBACK (onClickConM), 2);
    g_signal_connect (modButton,"button_press_event",G_CALLBACK (onClickConM), 3);

MYSQL *mysql;
    //Initialisation de MySQL
        mysql = mysql_init(NULL);
    //Options de connexion
        mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion réussie...
        if(mysql_real_connect(mysql,"localhost","root","","eboutique",0,NULL,0))
         {
            char req[1000];

            mysql_query(mysql,"select  * from user where type='adminM'");

            MYSQL_RES *result = NULL;
            MYSQL_ROW row;

 int y =450;
            int x=130;
            int ix =30;
            int iy =200;

              //On met le jeu de résultat dans le pointeur result
            result = mysql_use_result(mysql);

        //On récupère le nombre de champs


        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
            //On déclare un pointeur long non signé pour y stocker la taille des valeurs
            unsigned long *lengths;

            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);
               char text[50];



               sprintf(text,"%s",row[1]);
             GtkWidget *nomLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),nomLibele,x,y+50);
x=x+100;


             sprintf(text,"%s",row[2]);
             GtkWidget *prenomLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),prenomLibele,x,y+50);
x=x+100;


     sprintf(text,"%s",row[4]);
             GtkWidget *emailLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),emailLibele,x,y+50);
            x=x+200;

             sprintf(text,"%s",row[3]);
             GtkWidget *adresseLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),adresseLibele,x,y+50);
                 x=x+100;

             sprintf(text,"%s",row[7]);
             GtkWidget *villeLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),villeLibele,x,y+50);
                 x=x+100;
             sprintf(text,"%s",row[8]);
             GtkWidget *codeLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),codeLibele,x,y+50);
                 x=x+200;
             sprintf(text,"%s",row[6]);
             GtkWidget *telLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),telLibele,x,y+50);


             gtk_fixed_put(GTK_FIXED(fixed),modButton,1030,y);

  gtk_fixed_put(GTK_FIXED(fixed),effButton,1130,y);
x=x-800;
y=y+50;
            printf("\n");
        }

            mysql_free_result(result);
            mysql_close(mysql);
           }
             else
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }

  GdkColor colorB;
  //RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(modButton), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(BackButton), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(effButton), GTK_STATE_NORMAL, &colorB);
gtk_container_add(GTK_CONTAINER(consMWindow),fixed);
  GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);

 gtk_widget_show_all(consMWindow);

  gtk_main();
   }
void onDestroyConM(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}

static gboolean onClickConM( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {

        printf("%s \n",nom);
        printf("%s \n",image);

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
           //   sprintf(req,"update user set(nom,prenom,adresse,email,password,tel,ville,code_p,type) values ('%s','%s','%s','%s','%s','%s','%s','%s','%s')",nom,prenom,adresse,email,pass,tel,ville,code_p,type);

            mysql_query(mysql,req);

            insertion_msg3(consMWindow);
           //Fermeture de MySQL
            mysql_close(mysql);
           }
             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }
                     gtk_widget_hide(consMWindow);
                        AdminMagasin(argc,argv,text,idus,nomUser,prenomUser);
    }


    if(data == 2)
    {
        gtk_widget_hide(consMWindow);
          AdminG(argc,argv,text,idus,nomUser,prenomUser);

    }
     if(data == 3)
    {
       gtk_entry_set_text(GTK_ENTRY(nomText),"");
          gtk_entry_set_text(GTK_ENTRY(imageText),"");


    }

}
void insertion_msg3(gpointer data)
{
    GtkWidget *pAbout;
    gchar *info ="Insertion Success";

    pAbout = gtk_message_dialog_new(GTK_WINDOW(data),
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_CLOSE,
                                    info
                                    );
    gtk_dialog_run(GTK_DIALOG(pAbout));

    gtk_widget_destroy(pAbout);

    gtk_widget_hide(data);
      AdminMagasin(argc,argv,text,idus,nomUser,prenomUser);
}
