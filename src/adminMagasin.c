#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "adminMagasin.h"

  GtkWidget * AdminMagwindow;
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
      char *idus;
   char text[20];
char welcome [20];
char welcome1 [20];
  char nomUser[20];
  char prenomUser[20];
   void AdminMagasin(int argc, char **argv,char *email,char *iduser,char * nom,char *prenom) {
       gtk_init(&argc, &argv);
   idus=iduser;

       /* tout les parametres de mon fenetre authWindow" */
      AdminMagwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW( AdminMagwindow), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW ( AdminMagwindow), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW( AdminMagwindow), 1350, 700);
  gtk_window_set_position(GTK_WINDOW( AdminMagwindow), GTK_WIN_POS_CENTER);
  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER( AdminMagwindow), fixed);
         SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
      GtkWidget * RechImage = gtk_image_new_from_file("images/re.png");
      gtk_fixed_put(GTK_FIXED(fixed),RechImage,285,37);
  /*tout les parametre des buttons */
    btn1 = gtk_button_new_with_label("Ajouter Marques");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 80,550);
  gtk_widget_set_size_request(btn1, 80, 30);

 btn2 = gtk_button_new_with_label("Ajouter Produits");
  gtk_fixed_put(GTK_FIXED(fixed), btn2, 280,550);
  gtk_widget_set_size_request(btn2, 80, 30);

   btn3 = gtk_button_new_with_label("Consulter Produits");
  gtk_fixed_put(GTK_FIXED(fixed), btn3, 480,550);
  gtk_widget_set_size_request(btn3, 80, 30);

   btn4 = gtk_button_new_with_label("Consulter Clients");
  gtk_fixed_put(GTK_FIXED(fixed), btn4, 680,550);
  gtk_widget_set_size_request(btn4, 80, 30);
  gtk_widget_set_size_request(btn1, 80, 30);

  GtkWidget * btn5 = gtk_button_new_with_label("Deconexion");

  gtk_fixed_put(GTK_FIXED(fixed), btn5, 1210, 28);
  gtk_widget_set_size_request(btn5, 80, 30);
   g_signal_connect(G_OBJECT(AdminMagwindow),"destroy",G_CALLBACK(onDestroyAdminM),NULL);
 g_signal_connect(btn1,"button_press_event",G_CALLBACK (onClickAdminM), 1);
 g_signal_connect (btn2,"button_press_event",G_CALLBACK (onClickAdminM), 2);
  g_signal_connect (btn3,"button_press_event",G_CALLBACK (onClickAdminM), 3);
 g_signal_connect (btn4,"button_press_event",G_CALLBACK (onClickAdminM), 4);
  g_signal_connect (btn5,"button_press_event",G_CALLBACK (onClickAdminM), 5);
 //* couleurs du button*///
colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(btn1), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(btn2), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(btn3), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(btn4), GTK_STATE_NORMAL, &colorB);
	//* couleurs de fenetres*///

	//RGB(246^2,249^2,252^2)
	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(AdminMagwindow), GTK_STATE_NORMAL, &color);
	  GtkWidget  * ComLabel1 = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel1), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel1,850,250);
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
    gtk_widget_modify_bg(GTK_WIDGET(RechercheText), GTK_STATE_NORMAL, &colorB);
     RechercheLabel = gtk_label_new("Recherche");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Recherche</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( RechercheLabel ), sUtf8);
    g_free(sUtf8);
    gtk_fixed_put(GTK_FIXED(fixed),RechercheLabel,40,37);
  RechercheText = gtk_entry_new ();
gtk_entry_set_max_length (GTK_ENTRY (RechercheText), 50);
 gtk_fixed_put(GTK_FIXED(fixed),RechercheText,150,35);
 gtk_widget_show_all(AdminMagwindow);

  gtk_main();
   }
void onDestroyAdminM(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}

static gboolean onClickAdminM( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {
        gtk_widget_hide(AdminMagwindow);
        AjoutMarque(argc,argv);

    }

    if(data == 2)
    {
        gtk_widget_hide(AdminMagwindow);
          AjoutProduit(argc,argv);

    }
     if(data == 3)
    {
        gtk_widget_hide(AdminMagwindow);
    Consulteproduit(argc,argv);

    }
     if(data == 4)
    {
        gtk_widget_hide(AdminMagwindow);
        ConsulteClient(argc,argv);

    }
       if(data == 5)
    {
  gtk_widget_hide(AdminMagwindow);
        IndexPage1(argc,argv);
}
}
