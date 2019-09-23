#ifndef ADMING_H
#define ADMING_H

int argc;
char **argv;
char *email;
void onDestroyAdminG(GtkWidget *pwindow ,gpointer data);
void AdminG(int argc,char **argv,char *email,char *iduser,char *nom,char *prenom);
static gboolean onClickAdminG( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // ADMING_H
