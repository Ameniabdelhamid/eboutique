#ifndef MARQUE3_H
#define MARQUE3_H


int argc;
char **argv;

void Marque3(int argc,char **argv);
void onDestroyMarque3(GtkWidget *pwindow ,gpointer data);
static gboolean onClickMarques3( GtkWidget *widget,GdkEventButton *event,gpointer data );
//void Retour(GtkWidget *pwindow ,gpointer data);

#endif // MARQUE3_H
