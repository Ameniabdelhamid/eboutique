#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "ajoutproduit.h"

  GtkWidget * AjoutProduitW;
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
GtkWidget *nomLabel;
GtkWidget *refLabel;
GtkWidget *prixLabel;
GtkWidget *imageLabel;
GtkWidget *marqueLabel;

GtkWidget *nomText;
GtkWidget *refText;
GtkWidget *prixText;
GtkWidget *imageText;
GtkWidget *marqueText;
GtkWidget *nomImage;
GtkWidget *refImage;
GtkWidget *prixImage;
GtkWidget *imageImage;
GtkWidget *marqueImage;


      char *idus;
   char text[20];
char welcome [20];
char welcome1 [20];
  char nomUser[20];
  char prenomUser[20];
  GtkWidget *nomImage;
GtkWidget *imageText;
 GtkWidget *  nomText;
    const gchar *nomp,*refp,*prixp,*imagep,*marquep;
 void insertion_msg2(gpointer data);
   void AjoutProduit(int argc, char **argv) {
       gtk_init(&argc, &argv);

       /* tout les parametres de mon fenetre authWindow" */
    AjoutProduitW = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW( AjoutProduitW), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW ( AjoutProduitW), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW( AjoutProduitW), 1350, 700);
  gtk_window_set_position(GTK_WINDOW( AjoutProduitW), GTK_WIN_POS_CENTER);
  fixed = gtk_fixed_new();
  	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(AjoutProduitW), GTK_STATE_NORMAL, &color);
  gtk_container_add(GTK_CONTAINER( AjoutProduitW), fixed);
         SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
      GtkWidget * RechImage = gtk_image_new_from_file("images/re.png");
      gtk_fixed_put(GTK_FIXED(fixed),RechImage,285,37);

     GtkWidget * ForLabel = gtk_label_new("");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"200\" foreground=\"#920391\"><b>Ajout d'un produit</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ForLabel), sUtf8);
    g_free(sUtf8);
      nomLabel = gtk_label_new("Libellé  *");
    refLabel  = gtk_label_new("Réference  *");

     /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("Libellé  *\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( nomLabel), sUtf8);
    g_free(sUtf8);
     sUtf8 = g_locale_to_utf8("Réference *\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( refLabel), sUtf8);
    g_free(sUtf8);
    prixLabel = gtk_label_new("Prix  *");
    imageLabel  = gtk_label_new("Image  *");
    marqueLabel  = gtk_label_new("Marque  *");

  GtkWidget * champLabel =gtk_label_new("*Champs requis");


/*Button*/
  GtkWidget *confirmButton;
    GtkWidget * BackButton;
confirmButton = gtk_button_new_with_label("Ajouter");
BackButton = gtk_button_new_with_label("Retour");
  GtkWidget * resetButton = gtk_button_new_with_label("reset");
     g_signal_connect(G_OBJECT(AjoutProduitW),"destroy",G_CALLBACK(onDestroyPro),NULL);
  g_signal_connect (confirmButton,"button_press_event",G_CALLBACK (onClickPro), 1);
  g_signal_connect (BackButton,"button_press_event",G_CALLBACK (onClickPro), 2);
    g_signal_connect (resetButton,"button_press_event",G_CALLBACK (onClickPro), 3);
    /* entry properties */


    nomText = gtk_entry_new ();
    refText = gtk_entry_new ();
    prixText = gtk_entry_new ();
    imageText = gtk_entry_new ();
    marqueText = gtk_entry_new ();

    gtk_entry_set_max_length (GTK_ENTRY (nomText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (refText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (prixText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (imageText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (marqueText), 50);

    /* fixed properties */
    gtk_fixed_put(GTK_FIXED(fixed),ForLabel,55,400);
    gtk_fixed_put(GTK_FIXED(fixed),nomLabel,65,430);
    gtk_fixed_put(GTK_FIXED(fixed),refLabel,65,460);
    gtk_fixed_put(GTK_FIXED(fixed),prixLabel,65,490);
    gtk_fixed_put(GTK_FIXED(fixed),imageLabel,65,520);
    gtk_fixed_put(GTK_FIXED(fixed),marqueLabel,65,550);
     gtk_fixed_put(GTK_FIXED(fixed),champLabel,55,620);

    gtk_fixed_put(GTK_FIXED(fixed),nomImage,35,425);
    gtk_fixed_put(GTK_FIXED(fixed),refImage,35,455);
    gtk_fixed_put(GTK_FIXED(fixed),prixImage,35,455);
    gtk_fixed_put(GTK_FIXED(fixed),imageImage,35,455);
    gtk_fixed_put(GTK_FIXED(fixed),marqueImage,35,455);



    gtk_fixed_put(GTK_FIXED(fixed),nomText,250,430);
    gtk_fixed_put(GTK_FIXED(fixed),refText,250,460);
    gtk_fixed_put(GTK_FIXED(fixed),prixText,250,490);
    gtk_fixed_put(GTK_FIXED(fixed),imageText,250,520);
    gtk_fixed_put(GTK_FIXED(fixed),marqueText,250,550);



    gtk_fixed_put(GTK_FIXED(fixed),confirmButton,220,650);
  gtk_fixed_put(GTK_FIXED(fixed),BackButton,320,650);
  gtk_fixed_put(GTK_FIXED(fixed),resetButton,420,650);
  GdkColor colorB;
  //RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(confirmButton), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(BackButton), GTK_STATE_NORMAL, &colorB);
	gtk_widget_modify_bg(GTK_WIDGET(resetButton), GTK_STATE_NORMAL, &colorB);
gtk_container_add(GTK_CONTAINER(AjoutProduitW),fixed);
  GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);

 gtk_widget_show_all(AjoutProduitW);

  gtk_main();
   }
void onDestroyPro(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}

static gboolean onClickPro( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {
       char NewLogName[30];
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char s[100];
        strftime(s,30,"%x",timeinfo);
printf("%s\n",s);

        gchar *nomp,*refp,*prixp,*imagep,*marquep;

        nomp = gtk_entry_get_text (GTK_ENTRY (nomText));
        refp = gtk_entry_get_text (GTK_ENTRY (refText));
        prixp = gtk_entry_get_text (GTK_ENTRY (prixText));
        imagep = gtk_entry_get_text (GTK_ENTRY (imageText));
        marquep = gtk_entry_get_text (GTK_ENTRY (marqueText));
        printf("%s \n",nomp);
        printf("%s \n",refp);
        printf("%s \n",prixp);
        printf("%s \n",imagep);
        printf("%s \n",marquep);

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
             sprintf(req,"insert into produits (libille,ref,prix,image,marque,date) values ('%s','%s','%s','%s','%s','%s')",nomp,refp,prixp,imagep,marquep,s);

            mysql_query(mysql,req);

            insertion_msg2(AjoutProduitW);
           //Fermeture de MySQL
            mysql_close(mysql);
           }
             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }

                     gtk_widget_hide(AjoutProduitW);
                        AdminMagasin(argc,argv,text,idus,nomUser,prenomUser);
    }


    if(data == 2)
    {
        gtk_widget_hide(AjoutProduitW);
          AdminMagasin(argc,argv,text,idus,nomUser,prenomUser);

    }
     if(data == 3)
    {
       gtk_entry_set_text(GTK_ENTRY(nomText),"");
          gtk_entry_set_text(GTK_ENTRY(refText),"");
          gtk_entry_set_text(GTK_ENTRY(prixText),"");
          gtk_entry_set_text(GTK_ENTRY(imageText),"");
          gtk_entry_set_text(GTK_ENTRY(marqueText),"");


    }

}
void insertion_msg2(gpointer data)
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
