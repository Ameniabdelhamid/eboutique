#ifndef ADMINMAGASIN_H
#define ADMINMAGASIN_H
int argc;
char **argv;
char *email;
void onDestroyAdminM(GtkWidget *pwindow ,gpointer data);
void AdminMagasin(int argc,char **argv,char *email,char *iduser,char *nom,char *prenom);
static gboolean onClickAdminM( GtkWidget *widget,GdkEventButton *event,gpointer data );



#endif // ADMINMAGASIN_H
