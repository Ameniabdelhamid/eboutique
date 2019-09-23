#ifndef MARQUE1_H
#define MARQUE1_H

int argc;
char **argv;

void Marque(int argc,char **argv,char *idmar,char *nom);
void onDestroyMarque1(GtkWidget *pwindow ,gpointer data);
static gboolean onClickMarques1( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // MARQUE1_H
