#ifndef AFFICHE1_H
#define AFFICHE1_H

int argc;
char **argv;
char *idpro;
void Description(int argc,char **argv,char *idpro,char *libille,char *prix,char *image);
void onDestroyAffiche(GtkWidget *pwindow ,gpointer data);
static gboolean onClickAffiche( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // AFFICHE1_H
