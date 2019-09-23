#ifndef MARQUES_H
#define MARQUES_H

int argc;
char **argv;
char *login;
void marques(int argc,char **argv,char *login,char *iduser);
void onDestroyProfile(GtkWidget *pwindow ,gpointer data);
static gboolean onClickProfile( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // MARQUES_H
