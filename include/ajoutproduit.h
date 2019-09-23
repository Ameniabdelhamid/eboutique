#ifndef AJOUTPRODUIT_H
#define AJOUTPRODUIT_H

int argc;
char **argv;
char *email;
void onDestroyPro(GtkWidget *pwindow ,gpointer data);
void AjoutProduit(int argc,char **argv);
static gboolean onClickPro( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // AJOUTPRODUIT_H
