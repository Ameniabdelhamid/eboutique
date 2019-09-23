#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include <string.h>
#include "index.h"
#include "Inscription.h"
#include "connexion.h"
#include "ajoutadminmag.h"
  GtkWidget *window;
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
     const gchar *nom,*prenom,*adresse,*pass,*confirm,*tel,*ville,*email,*code_p;
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
GtkWidget *SlidIm;
  char *idus;
   char text[20];
char welcome [20];
char welcome1 [20];
  char nomUser[20];
  char prenomUser[20];
void insertion_msg4(gpointer data);
void InscriptionAdmin(int argc,char **argv)
{

/* tout les parametres de mon fenetre signupWindow" */
 InscritWindow= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(InscritWindow), "CoinMakeup Connexion");
gtk_window_set_icon_from_file(GTK_WINDOW (InscritWindow), "images/icon.jpg", NULL);
  gtk_window_set_default_size(GTK_WINDOW(InscritWindow), 1350, 700);
  gtk_window_set_position(GTK_WINDOW(InscritWindow), GTK_WIN_POS_CENTER);
   g_signal_connect(G_OBJECT(InscritWindow),"destroy",G_CALLBACK(onDestroyInscriptionAdmin),NULL);
fixed = gtk_fixed_new();
gtk_container_add(GTK_CONTAINER(InscritWindow),fixed);
  SlidIm= gtk_image_new_from_file("images/logo.jpg");
    gtk_fixed_put(GTK_FIXED(fixed),SlidIm,50,100);
  GdkColor color;
	//RGB(246^2,249^2,252^2)
	color.pixel = 0;
	color.red=65535;
	color.green=65535;
	color.blue=65535;
	gtk_widget_modify_bg(GTK_WIDGET(InscritWindow), GTK_STATE_NORMAL, &color);
     /*label properties */

     GtkWidget * ForLabel = gtk_label_new("Créez votre compte");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"200\" foreground=\"#920391\"><b>Créez votre compte</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ForLabel), sUtf8);
    g_free(sUtf8);
    nomLabel = gtk_label_new("Nom  *");
    prenomLabel  = gtk_label_new("Prénom");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("Prénom  *\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( prenomLabel), sUtf8);
    g_free(sUtf8);

   emailLabel =gtk_label_new("Email  *");
    passwordLabel = gtk_label_new("Mot De passe  *");
    confirmPasswordLabel =gtk_label_new("Confirmer Mot De Passe  *");
     adresseLabel = gtk_label_new("Adresse  *");
    villeLabel = gtk_label_new("Ville  *");
   code_pLabel =gtk_label_new("Code postal");
    telLabel = gtk_label_new("Téléphone  *");
   /* On utilise les balises */
    sUtf8 = g_locale_to_utf8("Télephone  *\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( telLabel), sUtf8);
    g_free(sUtf8);
  GtkWidget * champLabel =gtk_label_new("*Champs requis");



     nomImage = gtk_image_new_from_file("images/user.png");
    prenomImage = gtk_image_new_from_file("images/user.png");
    emailImage = gtk_image_new_from_file("images/email.png");
    passImage = gtk_image_new_from_file("images/pass.png");
    confirmImage = gtk_image_new_from_file("images/pass.png");
       adresseImage = gtk_image_new_from_file("images/adr.png");
    villeImage = gtk_image_new_from_file("images/v.png");
    code_pImage = gtk_image_new_from_file("images/ville.png");
    telImage = gtk_image_new_from_file("images/tel.png");
/*Button*/
  GtkWidget *confirmButton;
    GtkWidget * BackButton;
confirmButton = gtk_button_new_with_label("S'inscrire");
BackButton = gtk_button_new_with_label("Retour");
  GtkWidget * resetButton = gtk_button_new_with_label("reset");
  g_signal_connect (confirmButton,"button_press_event",G_CALLBACK (onClickInscriptionAdmin), 1);
  g_signal_connect (BackButton,"button_press_event",G_CALLBACK (onClickInscriptionAdmin), 2);
    g_signal_connect (resetButton,"button_press_event",G_CALLBACK (onClickInscriptionAdmin), 3);
    /* entry properties */


    nomText = gtk_entry_new ();
    prenomText = gtk_entry_new ();
  emailText = gtk_entry_new ();
    passwordText = gtk_entry_new ();
    confirmPasswordText = gtk_entry_new ();
       adresseText = gtk_entry_new ();
    villeText = gtk_entry_new ();
     code_pText = gtk_entry_new ();
    telText = gtk_entry_new ();
gtk_entry_set_visibility (GTK_ENTRY (passwordText),FALSE);
gtk_entry_set_visibility (GTK_ENTRY (confirmPasswordText),FALSE);
    gtk_entry_set_max_length (GTK_ENTRY (nomText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (prenomText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (emailText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (passwordText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (confirmPasswordText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (adresseText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (villeText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (code_pText), 50);
    gtk_entry_set_max_length (GTK_ENTRY (telText), 50);
    /* fixed properties */
    gtk_fixed_put(GTK_FIXED(fixed),ForLabel,55,400);
    gtk_fixed_put(GTK_FIXED(fixed),nomLabel,65,430);
    gtk_fixed_put(GTK_FIXED(fixed),prenomLabel,65,460);
    gtk_fixed_put(GTK_FIXED(fixed),emailLabel,65,490);
    gtk_fixed_put(GTK_FIXED(fixed),passwordLabel,65,520);
    gtk_fixed_put(GTK_FIXED(fixed),confirmPasswordLabel,65,550);
    gtk_fixed_put(GTK_FIXED(fixed),adresseLabel,470,430);
    gtk_fixed_put(GTK_FIXED(fixed),villeLabel,470,460);
    gtk_fixed_put(GTK_FIXED(fixed),code_pLabel,470,490);
    gtk_fixed_put(GTK_FIXED(fixed),telLabel,470,520);
     gtk_fixed_put(GTK_FIXED(fixed),champLabel,55,620);

    gtk_fixed_put(GTK_FIXED(fixed),nomImage,35,425);
    gtk_fixed_put(GTK_FIXED(fixed),prenomImage,35,455);
    gtk_fixed_put(GTK_FIXED(fixed),emailImage,35,485);
    gtk_fixed_put(GTK_FIXED(fixed),passImage,35,515);
    gtk_fixed_put(GTK_FIXED(fixed),confirmImage,35,545);
    gtk_fixed_put(GTK_FIXED(fixed),adresseImage,430,425);
    gtk_fixed_put(GTK_FIXED(fixed),villeImage,430,455);
    gtk_fixed_put(GTK_FIXED(fixed),code_pImage,430,485);
gtk_fixed_put(GTK_FIXED(fixed),telImage,430,515);


    gtk_fixed_put(GTK_FIXED(fixed),nomText,250,430);
    gtk_fixed_put(GTK_FIXED(fixed),prenomText,250,460);
    gtk_fixed_put(GTK_FIXED(fixed),emailText,250,490);
    gtk_fixed_put(GTK_FIXED(fixed),passwordText,250,520);
    gtk_fixed_put(GTK_FIXED(fixed),confirmPasswordText,250,550);
    gtk_fixed_put(GTK_FIXED(fixed),adresseText,550,430);
    gtk_fixed_put(GTK_FIXED(fixed),villeText,550,460);
    gtk_fixed_put(GTK_FIXED(fixed),code_pText,550,490);
    gtk_fixed_put(GTK_FIXED(fixed),telText,550,520);


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
gtk_container_add(GTK_CONTAINER(InscritWindow),fixed);
  GtkWidget  * ComLabel = gtk_label_new("Toujours plus de nouveautés sur CoinMakeup !");
       sUtf8 = g_locale_to_utf8("<span face=\"Georgia\" size=\"50\" foreground=\"#920391\"><b>Toujours plus de nouveautés sur CoinMakeup !</b></span>\n",-1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL( ComLabel), sUtf8);
    g_free(sUtf8);
     gtk_fixed_put(GTK_FIXED(fixed),ComLabel,850,250);

     gtk_widget_show_all(InscritWindow);
gtk_widget_show(InscritWindow);
    }

    void onDestroyInscriptionAdmin(GtkWidget *pWindow, gpointer data)
{
    gtk_main_quit();
}
static gboolean onClickInscriptionAdmin( GtkWidget *widget,GdkEventButton *event,gpointer data )
{
 if(data == 1)
    {

        gchar *nom,*prenom,*adresse,*pass,*confirm,*email,*tel,*ville,*code_p;

        nom = gtk_entry_get_text (GTK_ENTRY (nomText));
        prenom = gtk_entry_get_text (GTK_ENTRY (prenomText));
        adresse = gtk_entry_get_text (GTK_ENTRY (adresseText));
        pass = gtk_entry_get_text (GTK_ENTRY (passwordText));
        confirm = gtk_entry_get_text (GTK_ENTRY (confirmPasswordText));
        tel = gtk_entry_get_text (GTK_ENTRY (telText));
        ville = gtk_entry_get_text (GTK_ENTRY (villeText));
        email = gtk_entry_get_text (GTK_ENTRY (emailText));
          code_p = gtk_entry_get_text (GTK_ENTRY (code_pText));
        printf("%s \n",nom);
        printf("%s \n",prenom);
        printf("%s \n",adresse);
        printf("%s \n",pass);

        printf("%s \n",email);

        printf("%s \n",tel );
        printf("%s \n",code_p);
          printf("%s \n",ville);
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
            char *type="adminM";
              sprintf(req,"insert into user (nom,prenom,adresse,email,password,tel,ville,code_p,type) values ('%s','%s','%s','%s','%s','%s','%s','%s','%s')",nom,prenom,adresse,email,pass,tel,ville,code_p,type);

            mysql_query(mysql,req);

            insertion_msg4(InscritWindow);
           //Fermeture de MySQL
            mysql_close(mysql);
           }
             else  //Sinon ...
              {
                  printf("Une erreur s'est produite lors de la connexion à la BDD!");
              }
                      char* iduser;
                      iduser="5";
    sprintf(text,email);
    sprintf(nomUser,nom);
    sprintf(prenomUser,prenom);
    }

    if(data == 2)
    {
        char* iduser;
                      iduser="5";
        gtk_widget_hide(InscritWindow);
     AdminG(argc,argv,email,iduser, nom,prenom);

    }
      if (data == 3)
      {
          gtk_entry_set_text(GTK_ENTRY(nomText),"");
          gtk_entry_set_text(GTK_ENTRY(prenomText),"");
          gtk_entry_set_text(GTK_ENTRY(adresseText),"");
          gtk_entry_set_text(GTK_ENTRY(passwordText),"");
          gtk_entry_set_text(GTK_ENTRY(confirmPasswordText),"");
          gtk_entry_set_text(GTK_ENTRY(telText),"");
          gtk_entry_set_text(GTK_ENTRY(villeText),"");
          gtk_entry_set_text(GTK_ENTRY(emailText),"");
          gtk_entry_set_text(GTK_ENTRY(code_pText),"");
      }

}
void insertion_msg4(gpointer data)
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
   Connexion(argc,argv);
}

