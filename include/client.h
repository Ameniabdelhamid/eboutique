#ifndef CLIENT_H
#define CLIENT_H

int argc;
char **argv;
char *email;
void Clientt (int argc,char **argv,char *email,char *iduser,char *nom,char *prenom);
void onDestroyClient(GtkWidget *pwindow ,gpointer data);
static gboolean onClickClient( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // CLIENT_H
