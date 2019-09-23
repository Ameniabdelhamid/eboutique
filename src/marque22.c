#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include <string.h>
#include "index.h"
#include "Inscription.h"
#include "connexion.h"
#include "marque22.h"
  GtkWidget *MarqueImage1;
   GtkWidget *MarqueImage2;
   GtkWidget *MarqueImage3;
   GtkWidget *MarqueImage4;
        GtkWidget *Marque22Window;

GtkWidget *BackButton;
GtkWidget *confirmButton;
GtkWidget *resetButton;

GtkWidget *fixed;
gchar * sUtf8;

  GtkWidget *produitImage;
  GtkWidget *produitMarque;
  GtkWidget *produitLibele;
  GtkWidget *produitPrix;
  GtkWidget *produitCategorie;

  char *idus;
   char text[20];
char welcome [20];
char welcome1 [20];
  char nomUser[20];
  char prenomUser[20];
void Marque22(int argc, char **argv,char *email,char *iduser,char * nom,char *prenom)
{

/* tout les parametres de mon fenetre signupWindow" */
 Marque22Window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Marque22Window), "CoinMakeup ");
gtk_window_set_icon_from_file(GTK_WINDOW (Marque22Window), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW(Marque22Window), 1350, 700);
  gtk_window_set_position(GTK_WINDOW(Marque22Window), GTK_WIN_POS_CENTER);
   g_signal_connect(G_OBJECT(Marque22Window),"destroy",G_CALLBACK(onDestroyMarque22),NULL);
fixed = gtk_fixed_new();
gtk_container_add(GTK_CONTAINER(Marque22Window),fixed);
GtkWidget * SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
  GdkColor color;
	//RGB(246^2,249^2,252^2)
	color.pixel = 0;
	color.red=65535;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(Marque22Window), GTK_STATE_NORMAL, &color);
GtkWidget * resetButton = gtk_button_new_with_label("Retour");

     g_signal_connect (resetButton,"button_press_event",G_CALLBACK (onClickMarques22), 1);

          GdkColor colorB;
  //RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
     	gtk_widget_modify_bg(GTK_WIDGET(resetButton), GTK_STATE_NORMAL, &colorB);

     	  gtk_fixed_put(GTK_FIXED(fixed),resetButton,1250,650);

  GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);
    	    GtkWidget * RechImage = gtk_image_new_from_file("images/re.png");
      gtk_fixed_put(GTK_FIXED(fixed),RechImage,285,37);
GtkWidget *RechercheLabel = gtk_label_new("Recherche");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Recherche</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( RechercheLabel ), sUtf8);
    g_free(sUtf8);
    gtk_fixed_put(GTK_FIXED(fixed),RechercheLabel,40,37);
GtkWidget * RechercheText = gtk_entry_new ();
gtk_entry_set_max_length (GTK_ENTRY (RechercheText), 50);
 gtk_fixed_put(GTK_FIXED(fixed),RechercheText,150,35);

   MYSQL *mysql;
    //Initialisation de MySQL
        mysql = mysql_init(NULL);
    //Options de connexion
        mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion réussie...
        if(mysql_real_connect(mysql,"localhost","root","","eboutique",0,NULL,0))
         {
            char req[1000];

            mysql_query(mysql,"select  * from produits where marque='loreal paris'");

            MYSQL_RES *result = NULL;
            MYSQL_ROW row;

 int y =400;
            int x=30;
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
GtkWidget * transImageS = gtk_image_new_from_file(row[6]);
    GtkWidget * transButtonS = gtk_button_new_with_label("");

	gtk_widget_modify_bg(GTK_WIDGET(transButtonS), GTK_STATE_NORMAL, &colorB);
    gtk_button_set_image(GTK_BUTTON(transButtonS), transImageS);
    gtk_button_set_image_position(GTK_BUTTON(transButtonS), GTK_POS_BOTTOM);

 gtk_fixed_put(GTK_FIXED(fixed),transButtonS,x,y+10);
     g_signal_connect (transButtonS,"button_press_event",G_CALLBACK (onClickMarques22), 2);
x=x-30;
//gtk_fixed_put(GTK_FIXED(fixed),produitImage,x,y+10);

              /* giftLabelConverti*/
         GtkWidget *Libelle = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#FF358B\" size=\"large\"><b>Libellé :</b></span>", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
             GtkWidget *LibeleLabel = gtk_label_new(Libelle);
             g_free(Libelle); // Libération de la mémoire
             gtk_label_set_use_markup(GTK_LABEL(LibeleLabel), TRUE); // On dit que l'on utilise les balises pango
             gtk_label_set_justify(GTK_LABEL(LibeleLabel), GTK_JUSTIFY_CENTER);
             gtk_fixed_put(GTK_FIXED(fixed),LibeleLabel,x+30,y+220);

               sprintf(text,"%s",row[1]);
             GtkWidget *produitLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),produitLibele,x+100,y+222);
             x=x+150;

           GtkWidget *prix = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#FF358B\" size=\"large\"><b>Prix :</b></span>", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
           GtkWidget * prixlabel = gtk_label_new(prix);
             g_free(prix); // Libération de la mémoire
             gtk_label_set_use_markup(GTK_LABEL(prixlabel), TRUE); // On dit que l'on utilise les balises pango
             gtk_label_set_justify(GTK_LABEL(prixlabel), GTK_JUSTIFY_CENTER);
             gtk_fixed_put(GTK_FIXED(fixed),prixlabel,x-120,y+250);

             sprintf(text,"%s",row[5]);
             GtkWidget *produitPrix= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),produitPrix,x-70,y+252);

             x=x+150;

            printf("\n");
        }

            mysql_free_result(result);
            mysql_close(mysql);
           }
             else
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }
           idus=iduser;
    sprintf(text,email);
    sprintf(nomUser,nom);
    sprintf(prenomUser,prenom);

	 gtk_widget_show_all(Marque22Window);

  gtk_main();
}
    void onDestroyMarque22(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}
static gboolean onClickMarques22( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {

        gtk_widget_hide(Marque22Window);
       Client(argc,argv,text,idus,nomUser,prenomUser);

    }
     if(data == 2)
    {
/**
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
              sprintf(req,"insert into panier (idpro,iduser,prix,libele,qte) values ('%s','%s','%s','%s','%s')",nom,prenom,adresse,email,pass,tel,ville,code_p);

            mysql_query(mysql,req);

            insertion_msg(InscritWindow);
           //Fermeture de MySQL
            mysql_close(mysql);
           }
             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }

**/
        gtk_widget_hide(Marque22Window);
          Marque22(argc,argv,text,idus,nomUser,prenomUser);

    }
}
