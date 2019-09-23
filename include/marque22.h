#ifndef MARQUE22_H
#define MARQUE22_H
int argc;
char **argv;

void Marque22(int argc,char **argv,char *email,char *iduser,char *nom, char * prenom);
void onDestroyMarque22(GtkWidget *pwindow ,gpointer data);
static gboolean onClickMarques22( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // MARQUE22_H
