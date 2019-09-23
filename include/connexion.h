#ifndef CONNEXION_H
#define CONNEXION_H


void Connexion(int argc,char **argv);
void onDestroyConnect(GtkWidget *pwindow ,gpointer data);
static gboolean onClickConnect( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // CONNEXION_H
