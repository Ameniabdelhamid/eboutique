#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "ajoutmarque.h"

  GtkWidget * AjoutMarqueW;
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
GtkWidget *imageLabel;
GtkWidget * InscritWindow;
GtkWidget * window;
GtkWidget *nomText;
GtkWidget *imageText;
GtkWidget *nomImage;
GtkWidget *imageImage;


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
 void insertion_msg1(gpointer data);
   void AjoutMarque(int argc, char **argv) {
       gtk_init(&argc, &argv);

       /* tout les parametres de mon fenetre authWindow" */
    AjoutMarqueW = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW( AjoutMarqueW), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW ( AjoutMarqueW), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW( AjoutMarqueW), 1350, 700);
  gtk_window_set_position(GTK_WINDOW( AjoutMarqueW), GTK_WIN_POS_CENTER);
  fixed = gtk_fixed_new();
  	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(AjoutMarqueW), GTK_STATE_NORMAL, &color);
  gtk_container_add(GTK_CONTAINER( AjoutMarqueW), fixed);
         SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
      GtkWidget * RechImage = gtk_image_new_from_file("images/re.png");
      gtk_fixed_put(GTK_FIXED(fixed),RechImage,285,37);

     GtkWidget * ForLabel = gtk_label_new("");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"200\" foreground=\"#920391\"><b>Ajout d'un produit</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ForLabel), sUtf8);
    g_free(sUtf8);
    nomLabel = gtk_label_new("Nom  *");
    imageLabel  = gtk_label_new("Image  *");

  GtkWidget * champLabel =gtk_label_new("*Champs requis");

    imageImage = gtk_image_new_from_file("images/im.png");

/*Button*/
  GtkWidget *confirmButton;
    GtkWidget * BackButton;
confirmButton = gtk_button_new_with_label("Ajouter");
BackButton = gtk_button_new_with_label("Retour");
  GtkWidget * resetButton = gtk_button_new_with_label("reset");
     g_signal_connect(G_OBJECT(AjoutMarqueW),"destroy",G_CALLBACK(onDestroyMar),NULL);
  g_signal_connect (confirmButton,"button_press_event",G_CALLBACK (onClickMar), 1);
  g_signal_connect (BackButton,"button_press_event",G_CALLBACK (onClickMar), 2);
    g_signal_connect (resetButton,"button_press_event",G_CALLBACK (onClickMar), 3);
    /* entry properties */


    nomText = gtk_entry_new ();
    imageText = gtk_entry_new ();

    gtk_entry_set_max_length (GTK_ENTRY (nomText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (imageText), 50);

    /* fixed properties */
    gtk_fixed_put(GTK_FIXED(fixed),ForLabel,55,400);
    gtk_fixed_put(GTK_FIXED(fixed),nomLabel,65,430);
    gtk_fixed_put(GTK_FIXED(fixed),imageLabel,65,460);

     gtk_fixed_put(GTK_FIXED(fixed),champLabel,55,620);

    gtk_fixed_put(GTK_FIXED(fixed),nomImage,35,425);
    gtk_fixed_put(GTK_FIXED(fixed),imageImage,35,455);



    gtk_fixed_put(GTK_FIXED(fixed),nomText,250,430);
    gtk_fixed_put(GTK_FIXED(fixed),imageText,250,460);



    gtk_fixed_put(GTK_FIXED(fixed),confirmButton,220,500);
  gtk_fixed_put(GTK_FIXED(fixed),BackButton,320,500);
  gtk_fixed_put(GTK_FIXED(fixed),resetButton,420,500);
  GdkColor colorB;
  //RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(confirmButton), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(BackButton), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(resetButton), GTK_STATE_NORMAL, &colorB);
gtk_container_add(GTK_CONTAINER(AjoutMarqueW),fixed);
  GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);

 gtk_widget_show_all(AjoutMarqueW);

  gtk_main();
   }
void onDestroyMar(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}

static gboolean onClickMar( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {


        gchar *nom,*image;

        nom = gtk_entry_get_text (GTK_ENTRY (nomText));
        image = gtk_entry_get_text (GTK_ENTRY (imageText));

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
              sprintf(req,"insert into marque (nom,image) values ('%s','%s')",nom,image);

            mysql_query(mysql,req);

            insertion_msg1(AjoutMarqueW);
           //Fermeture de MySQL
            mysql_close(mysql);
           }
             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }
                     gtk_widget_hide(AjoutMarqueW);
                        AdminMagasin(argc,argv,text,idus,nomUser,prenomUser);
    }


    if(data == 2)
    {
        gtk_widget_hide(AjoutMarqueW);
          AdminMagasin(argc,argv,text,idus,nomUser,prenomUser);

    }
     if(data == 3)
    {
       gtk_entry_set_text(GTK_ENTRY(nomText),"");
          gtk_entry_set_text(GTK_ENTRY(imageText),"");


    }

}
void insertion_msg1(gpointer data)
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
