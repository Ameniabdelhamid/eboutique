#ifndef MARQUE2_H
#define MARQUE2_H

int argc;
char **argv;

void Marque2(int argc,char **argv);
void onDestroyMarque2(GtkWidget *pwindow ,gpointer data);
static gboolean onClickMarques2( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // MARQUE2_H
