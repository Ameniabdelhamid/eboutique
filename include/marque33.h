#ifndef MARQUE33_H
#define MARQUE33_H
int argc;
char **argv;

void Marque33(int argc,char **argv,char *email,char *iduser,char *nom, char * prenom);
void onDestroyMarque33(GtkWidget *pwindow ,gpointer data);
static gboolean onClickMarques33( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // MARQUE33_H
