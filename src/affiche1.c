#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "marque1.h";
#include "affiche1.h"
#include "connexion.h"
  GtkWidget * Affiche1window;
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
   char *idp;
   char text[20];
char welcome [20];
char welcome1 [20];
  char prixT[20];
  char imageT[20];
void Description(int argc, char **argv,char *idpro,char *libille,char * prix,char *image) {
       gtk_init(&argc, &argv);
       idp=idpro;

       /* tout les parametres de mon fenetre authWindow" */
     Affiche1window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW( Affiche1window), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW ( Affiche1window), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW( Affiche1window), 1350, 700);
  gtk_window_set_position(GTK_WINDOW( Affiche1window), GTK_WIN_POS_CENTER);
  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER( Affiche1window), fixed);

 int y =400;
            int x=30;
            int ix =30;
            int iy =200;
                sprintf(text,libille);
    sprintf(prixT,prix);
    sprintf(imageT,image);
            GtkWidget * transImageS = gtk_image_new_from_file(imageT);
    GtkWidget * transButtonS = gtk_button_new_with_label("");

	gtk_widget_modify_bg(GTK_WIDGET(transButtonS), GTK_STATE_NORMAL, &colorB);
    gtk_button_set_image(GTK_BUTTON(transButtonS), transImageS);
    gtk_button_set_image_position(GTK_BUTTON(transButtonS), GTK_POS_BOTTOM);

 gtk_fixed_put(GTK_FIXED(fixed),transButtonS,x+150,y+40);

x=x-30;
             /* giftLabelConverti*/
         GtkWidget *Libelle = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#FF358B\" size=\"large\"><b>Libellé :</b></span>", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
             GtkWidget *LibeleLabel = gtk_label_new(Libelle);
             g_free(Libelle); // Libération de la mémoire
             gtk_label_set_use_markup(GTK_LABEL(LibeleLabel), TRUE); // On dit que l'on utilise les balises pango
             gtk_label_set_justify(GTK_LABEL(LibeleLabel), GTK_JUSTIFY_CENTER);
             gtk_fixed_put(GTK_FIXED(fixed),LibeleLabel,x+450,y+60);

               //sprintf(text,"%s",row[1]);
             GtkWidget *produitLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),produitLibele,x+550,y+60);
             x=x+150;

           GtkWidget *prixs = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#FF358B\" size=\"large\"><b>Prix :</b></span>", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
           GtkWidget * prixlabel = gtk_label_new(prixs);
             g_free(prixs); // Libération de la mémoire
             gtk_label_set_use_markup(GTK_LABEL(prixlabel), TRUE); // On dit que l'on utilise les balises pango
             gtk_label_set_justify(GTK_LABEL(prixlabel), GTK_JUSTIFY_CENTER);
             gtk_fixed_put(GTK_FIXED(fixed),prixlabel,x+300,y+100);


             GtkWidget *produitPrix= gtk_label_new(prixT);
             gtk_fixed_put(GTK_FIXED(fixed),produitPrix,x+400,y+100);

             x=x+150;




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
	gtk_widget_modify_bg(GTK_WIDGET( Affiche1window), GTK_STATE_NORMAL, &color);


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
 GtkWidget * resetButton = gtk_button_new_with_label("Retour");

     g_signal_connect (resetButton,"button_press_event",G_CALLBACK (onClickAffiche), 1);

          GdkColor colorB;
  //RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
     	gtk_widget_modify_bg(GTK_WIDGET(resetButton), GTK_STATE_NORMAL, &colorB);

     	  gtk_fixed_put(GTK_FIXED(fixed),resetButton,450,650);
 gtk_widget_show_all( Affiche1window);

  gtk_main();
   }

void onDestroyAffiche(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}

static gboolean onClickAffiche( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {

    gtk_widget_hide(Affiche1window);
         // Marque(argc,argv,idmar);
    }




}
