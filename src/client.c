#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "marque1.h";
#include "client.h"
#include "connexion.h"
  GtkWidget *Clientwindow;
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
   GdkColor color;
   GdkColor colorB;
   char *idus;
   char text[20];
char welcome [20];
char welcome1 [20];
  char nomUser[20];
  char prenomUser[20];
void Client(int argc, char **argv,char *email,char *iduser,char * nom,char *prenom) {
       gtk_init(&argc, &argv);
       idus=iduser;

       /* tout les parametres de mon fenetre authWindow" */
      Clientwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Clientwindow), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW (Clientwindow), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW(Clientwindow), 1350, 700);
  gtk_window_set_position(GTK_WINDOW(Clientwindow), GTK_WIN_POS_CENTER);
  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(Clientwindow), fixed);
  /*tout les parametre des buttons */
    btn1 = gtk_button_new_with_label("Mon Panier");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 1100,28);
  gtk_widget_set_size_request(btn1, 80, 30);
   GtkWidget * btn2 = gtk_button_new_with_label("Deconexion");

  gtk_fixed_put(GTK_FIXED(fixed), btn2, 1210, 28);
  gtk_widget_set_size_request(btn2, 80, 30);
  GtkWidget *DconxImage = gtk_image_new_from_file("images/s.png");
    gtk_fixed_put(GTK_FIXED(fixed),  DconxImage,1180,33);

    sprintf(text,email);
    sprintf(nomUser,nom);
    sprintf(prenomUser,prenom);
    sprintf(welcome," %s",nomUser );
    sprintf(welcome1,"%s",prenomUser );
    GtkWidget *welcomeLabel =gtk_label_new("");
GtkWidget *loginLabel =gtk_label_new(welcome);
GtkWidget *loginLabel1 =gtk_label_new(welcome1);
  sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#f194ac\"><b>Bienvenu</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( welcomeLabel ), sUtf8);
    g_free(sUtf8);
  gtk_fixed_put(GTK_FIXED(fixed),welcomeLabel,50,400);
    gtk_fixed_put(GTK_FIXED(fixed),loginLabel,130,402);
    gtk_fixed_put(GTK_FIXED(fixed),loginLabel1,200,402);
  /////// Button Marque 1 //////////
GtkWidget * transImageS = gtk_image_new_from_file("images/rv.png");
    GtkWidget * transButtonS = gtk_button_new_with_label("");
     color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(transButtonS), GTK_STATE_NORMAL, &color);
    gtk_button_set_image(GTK_BUTTON(transButtonS), transImageS);
    gtk_button_set_image_position(GTK_BUTTON(transButtonS), GTK_POS_BOTTOM);

 gtk_fixed_put(GTK_FIXED(fixed),transButtonS,100,470);
  gtk_widget_show(GTK_WIDGET(transImageS));



	/////// Button Marque 2 //////////
GtkWidget * transImage1 = gtk_image_new_from_file("images/pa.png");
    GtkWidget * transButton1 = gtk_button_new_with_label("");
     color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(transButton1), GTK_STATE_NORMAL, &color);
    gtk_button_set_image(GTK_BUTTON(transButton1), transImage1);
    gtk_button_set_image_position(GTK_BUTTON(transButton1), GTK_POS_BOTTOM);

 gtk_fixed_put(GTK_FIXED(fixed),transButton1,400,470);
  gtk_widget_show(GTK_WIDGET(transImage1));

  /////// Button Marque 3 //////////
GtkWidget * transImage2 = gtk_image_new_from_file("images/ny.png");
    GtkWidget * transButton2 = gtk_button_new_with_label("");
     color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(transButton2), GTK_STATE_NORMAL, &color);
    gtk_button_set_image(GTK_BUTTON(transButton2), transImage2);
    gtk_button_set_image_position(GTK_BUTTON(transButton2), GTK_POS_BOTTOM);

 gtk_fixed_put(GTK_FIXED(fixed),transButton2,700,470);
  gtk_widget_show(GTK_WIDGET(transImage2));


   /////// Button Marque 3 //////////
GtkWidget * transImage3 = gtk_image_new_from_file("images/nina.png");
    GtkWidget * transButton3 = gtk_button_new_with_label("");

     color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(transButton3), GTK_STATE_NORMAL, &color);
    gtk_button_set_image(GTK_BUTTON(transButton3), transImage3);
    gtk_button_set_image_position(GTK_BUTTON(transButton3), GTK_POS_BOTTOM);

 gtk_fixed_put(GTK_FIXED(fixed),transButton3,1000,470);
  gtk_widget_show(GTK_WIDGET(transImage3));
 //g_signal_connect (btn2,"button_press_event",G_CALLBACK (onClick), 2);
 g_signal_connect(G_OBJECT(Clientwindow),"destroy",G_CALLBACK(onDestroyClient),NULL);

//////////////*Marques*////////////
 g_signal_connect(transButtonS,"button_press_event",G_CALLBACK (onClickClient), 1);
 g_signal_connect (transButton1,"button_press_event",G_CALLBACK (onClickClient), 2);
  g_signal_connect (transButton2,"button_press_event",G_CALLBACK (onClickClient), 3);
 g_signal_connect (transButton3,"button_press_event",G_CALLBACK (onClickClient), 4);
  g_signal_connect (btn1,"button_press_event",G_CALLBACK (onClickClient), 5);
   g_signal_connect (btn2,"button_press_event",G_CALLBACK (onClickClient), 6);
/* tout les parametre des labels */
   RechercheLabel = gtk_label_new("Recherche");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Recherche</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( RechercheLabel ), sUtf8);
    g_free(sUtf8);
    gtk_fixed_put(GTK_FIXED(fixed),RechercheLabel,40,37);
     MarqueLabel = gtk_label_new("Marques");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"100\" foreground=\"#920391\"><b>Marques</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( MarqueLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),MarqueLabel,90,440);

   GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);
/* tout les parametre des champs de text */
    RechercheText = gtk_entry_new ();
gtk_entry_set_max_length (GTK_ENTRY (RechercheText), 50);
 gtk_fixed_put(GTK_FIXED(fixed),RechercheText,150,35);
 /* tout les parametre des images */
   conxImage = gtk_image_new_from_file("images/pan.png");
    gtk_fixed_put(GTK_FIXED(fixed),  conxImage,1040,18);

       SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
      GtkWidget * RechImage = gtk_image_new_from_file("images/re.png");
      gtk_fixed_put(GTK_FIXED(fixed),RechImage,285,37);
      //* couleurs de fenetres*///

	//RGB(246^2,249^2,252^2)
	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(Clientwindow), GTK_STATE_NORMAL, &color);


	//RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(btn1), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(btn2), GTK_STATE_NORMAL, &colorB);
gtk_widget_modify_bg(GTK_WIDGET(RechercheText), GTK_STATE_NORMAL, &colorB);
  GtkWidget  * Label = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( Label), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),Label,850,250);

         	    GtkWidget * RechImage1 = gtk_image_new_from_file("images/re.png");
      gtk_fixed_put(GTK_FIXED(fixed),RechImage1,285,37);
  RechercheLabel = gtk_label_new("Recherche");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Recherche</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( RechercheLabel ), sUtf8);
    g_free(sUtf8);
    gtk_fixed_put(GTK_FIXED(fixed),RechercheLabel,40,37);
  RechercheText = gtk_entry_new ();
gtk_entry_set_max_length (GTK_ENTRY (RechercheText), 50);
 gtk_fixed_put(GTK_FIXED(fixed),RechercheText,150,35);
 gtk_widget_show_all(Clientwindow);

  gtk_main();
   }

void onDestroyClient(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}
static gboolean onClick( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {
        gtk_widget_hide(Clientwindow);
        Connexion(argc,argv);

    }
}
static gboolean onClickClient( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {

        gtk_widget_hide(Clientwindow);
        Marque11(argc,argv,text,idus,nomUser,prenomUser);


    }

    if(data == 2)
    {
        gtk_widget_hide(Clientwindow);
         Marque22(argc,argv,text,idus,nomUser,prenomUser);

    }
     if(data == 3)
    {
        gtk_widget_hide(Clientwindow);
        Marque33(argc,argv,text,idus,nomUser,prenomUser);

    }
     if(data == 4)
    {
        gtk_widget_hide(Clientwindow);
        //Marque44(argc,argv);

    }
       if(data == 5)
    {
        gtk_widget_hide(Clientwindow);
        //Marque4(argc,argv,text,idus);

    }

       if(data == 6)
    {
        gtk_widget_hide(Clientwindow);
        IndexPage1(argc,argv);

    }


}
