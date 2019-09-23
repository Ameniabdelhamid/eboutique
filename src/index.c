#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <time.h>
#include <sys/time.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "index.h"
#include "marque1.h";
   char text[20];
char welcome [20];
char welcome1 [20];
  char prixT[20];
  char imageT[20];
   char marqueT[20];
  GtkWidget *window;
  GtkWidget *Connectwindow;
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
   char *idmar[50];
   void insertion_msg22(gpointer data);
void IndexPage1(int argc, char **argv)
{
    GtkWidget* window;
    GtkWidget* box;
    GtkWidget *scrollbar;
    int i;

 gtk_init(&argc,&argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "CoinMakeup");
gtk_window_set_icon_from_file(GTK_WINDOW (window), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW(window), 1350, 700);
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
  //g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(onDestroyOffre),NULL);

    scrollbar = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window),scrollbar);

    box=gtk_vbox_new(FALSE,5);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollbar), box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollbar), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);


fixed = gtk_fixed_new ();
  gtk_widget_show (fixed);
  gtk_container_add (GTK_CONTAINER (box), fixed);
btn1 = gtk_button_new_with_label("Connexion ");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 1090,20);
  gtk_widget_set_size_request(btn1, 80, 30);
    btn2 = gtk_button_new_with_label("Inscription");
  gtk_fixed_put(GTK_FIXED(fixed), btn2, 1200, 20);
  gtk_widget_set_size_request(btn2, 80, 30);
 g_signal_connect (btn1,"button_press_event",G_CALLBACK (onClick), 1);
 g_signal_connect (btn2,"button_press_event",G_CALLBACK (onClick), 2);
 g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(onDestroy),NULL);




    GtkWidget *nouveau= gtk_image_new_from_file("images/new.gif");
    gtk_fixed_put(GTK_FIXED(fixed),nouveau,90,370);

	//RGB(246^2,249^2,252^2)
	colorB.pixel = 0;
	colorB.red=63504;
	colorB.green=95094;
	colorB.blue=51984;
	gtk_widget_modify_bg(GTK_WIDGET(btn1), GTK_STATE_NORMAL, &colorB);
gtk_widget_modify_bg(GTK_WIDGET(btn2), GTK_STATE_NORMAL, &colorB);
gtk_widget_modify_bg(GTK_WIDGET(RechercheText), GTK_STATE_NORMAL, &colorB);
  GtkWidget  * ComLabel1 = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel1), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel1,850,250);
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
   conxImage = gtk_image_new_from_file("images/s.png");
    gtk_fixed_put(GTK_FIXED(fixed),  conxImage,1045,23);
     InscritImage = gtk_image_new_from_file("images/user.png");
    gtk_fixed_put(GTK_FIXED(fixed),InscritImage,1175,23);
       SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
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
       char NewLogName[30];
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char y[100];
        strftime(y,30,"%Y ",timeinfo);
printf("%s\n",y);
  char m[100];
        strftime(m,30,"%d ",timeinfo);
printf("%s\n",m);
char *j="01";
char *j1="31";


            mysql_query(mysql,"SELECT * FROM produits where date between'01/12/2016' and '31/12/2016'");

            MYSQL_RES *result = NULL;
            MYSQL_ROW row;

 int p =400;
            int q=30;


              //On met le jeu de résultat dans le pointeur result
            result = mysql_use_result(mysql);

        //On récupère le nombre de champs


        //Tant qu'il y a encore un résultat ...
       while ((row = mysql_fetch_row(result)))
        {

GtkWidget * transImageS = gtk_image_new_from_file(row[4]);
    GtkWidget * transButtonS = gtk_button_new_with_label("");

	gtk_widget_modify_bg(GTK_WIDGET(transButtonS), GTK_STATE_NORMAL, &colorB);
    gtk_button_set_image(GTK_BUTTON(transButtonS), transImageS);
    gtk_button_set_image_position(GTK_BUTTON(transButtonS), GTK_POS_BOTTOM);

 gtk_fixed_put(GTK_FIXED(fixed),transButtonS,q-20,p+30);
 gtk_widget_set_size_request(transButtonS, 80, 30);
q=q-60;
//gtk_fixed_put(GTK_FIXED(fixed),produitImage,x,y+10);

              /* giftLabelConverti*/
         GtkWidget *Libelle = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#FF358B\" size=\"large\"><b>Libellé :</b></span>", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
             GtkWidget *LibeleLabel = gtk_label_new(Libelle);
             g_free(Libelle); // Libération de la mémoire
             gtk_label_set_use_markup(GTK_LABEL(LibeleLabel), TRUE); // On dit que l'on utilise les balises pango
             gtk_label_set_justify(GTK_LABEL(LibeleLabel), GTK_JUSTIFY_CENTER);
             gtk_fixed_put(GTK_FIXED(fixed),LibeleLabel,q+40,p+200);

               sprintf(text,"%s",row[1]);
             GtkWidget *produitLibele= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),produitLibele,q+110,p+202);
             q=q+100;

           GtkWidget *prix = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#FF358B\" size=\"large\"><b>Prix :</b></span>", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
           GtkWidget * prixlabel = gtk_label_new(prix);
             g_free(prix); // Libération de la mémoire
             gtk_label_set_use_markup(GTK_LABEL(prixlabel), TRUE); // On dit que l'on utilise les balises pango
             gtk_label_set_justify(GTK_LABEL(prixlabel), GTK_JUSTIFY_CENTER);
             gtk_fixed_put(GTK_FIXED(fixed),prixlabel,q-60,p+220);

             sprintf(text,"%s",row[3]);
             GtkWidget *produitPrix= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),produitPrix,q,p+222);

             q=q+100;

           GtkWidget *marque = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#FF358B\" size=\"large\"><b>Marque :</b></span>", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
           GtkWidget * marquelabel = gtk_label_new(marque);
             g_free(marque); // Libération de la mémoire
             gtk_label_set_use_markup(GTK_LABEL(marquelabel), TRUE); // On dit que l'on utilise les balises pango
             gtk_label_set_justify(GTK_LABEL(marquelabel), GTK_JUSTIFY_CENTER);
             gtk_fixed_put(GTK_FIXED(fixed),marquelabel,q-160,p+240);

             sprintf(text,"%s",row[5]);
             GtkWidget *produitmarque= gtk_label_new(text);
             gtk_fixed_put(GTK_FIXED(fixed),produitmarque,q-70,p+242);

             q=q+100;

        }

            mysql_free_result(result);
           //Fermeture de MySQL
            mysql_close(mysql);


   }

             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }

            insertion_msg22(window);



    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
void onDestroy(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}
static gboolean onClick( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {
        gtk_widget_hide(window);
        Connexion(argc,argv);

    }

    if(data == 2)
    {
        gtk_widget_hide(window);
        Inscription(argc,argv);

    }

}
static gboolean onClickMarques( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {

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
       char NewLogName[30];
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char y[100];
        strftime(y,30,"%Y ",timeinfo);
printf("%s\n",y);
  char m[100];
        strftime(m,30,"%d ",timeinfo);
printf("%s\n",m);
char *j="01";
char *j1="31";


            mysql_query(mysql,"SELECT idmar,nom,image FROM marque ");

            MYSQL_RES *result = NULL;
            MYSQL_ROW row;

 int p =700;
            int q=30;


              //On met le jeu de résultat dans le pointeur result
            result = mysql_use_result(mysql);

        //On récupère le nombre de champs


        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {

               sprintf(idmar,"%s",row[0]);
printf("%s \n",idmar);
GtkWidget * transImageS = gtk_image_new_from_file(row[2]);
    GtkWidget * transButtonS = gtk_button_new_with_label("");

	gtk_widget_modify_bg(GTK_WIDGET(transButtonS), GTK_STATE_NORMAL, &colorB);
    gtk_button_set_image(GTK_BUTTON(transButtonS), transImageS);
    gtk_button_set_image_position(GTK_BUTTON(transButtonS), GTK_POS_BOTTOM);
  g_signal_connect(transButtonS,"button_press_event",G_CALLBACK (onClickMarques), 1);
 gtk_fixed_put(GTK_FIXED(fixed),transButtonS,q,p+30);
 gtk_widget_set_size_request(transButtonS, 80, 30);
q=q+180;

    gtk_widget_hide(window);
        char *nom[20];
        sprintf(nom,"%s \n",row[1]);
        Marque(argc,argv,idmar,nom);
        }

            mysql_free_result(result);
           //Fermeture de MySQL
            mysql_close(mysql);


   }

             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }


    }


}

void insertion_msg22(gpointer data)
{
         MarqueLabel = gtk_label_new("Marques");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"100\" foreground=\"#920391\"><b>Marques</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( MarqueLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),MarqueLabel,30,680);

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
       char NewLogName[30];
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char y[100];
        strftime(y,30,"%Y ",timeinfo);
printf("%s\n",y);
  char m[100];
        strftime(m,30,"%d ",timeinfo);
printf("%s\n",m);
char *j="01";
char *j1="31";


            mysql_query(mysql,"SELECT idmar,nom,image FROM marque ");

            MYSQL_RES *result = NULL;
            MYSQL_ROW row;

 int p =700;
            int q=30;


              //On met le jeu de résultat dans le pointeur result
            result = mysql_use_result(mysql);

        //On récupère le nombre de champs


        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {

               sprintf(idmar,"%s",row[0]);
sprintf(text,"%s",row[1]);
GtkWidget * transImageS = gtk_image_new_from_file(row[2]);
    GtkWidget * transButtonS = gtk_button_new_with_label("");

	gtk_widget_modify_bg(GTK_WIDGET(transButtonS), GTK_STATE_NORMAL, &colorB);
    gtk_button_set_image(GTK_BUTTON(transButtonS), transImageS);
    gtk_button_set_image_position(GTK_BUTTON(transButtonS), GTK_POS_BOTTOM);
  g_signal_connect(transButtonS,"button_press_event",G_CALLBACK (onClickMarques), 1);
 gtk_fixed_put(GTK_FIXED(fixed),transButtonS,q,p+30);
 gtk_widget_set_size_request(transButtonS, 80, 30);
q=q+180;


        }

            mysql_free_result(result);
           //Fermeture de MySQL
            mysql_close(mysql);


   }

             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }
}
