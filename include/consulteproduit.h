#ifndef CONSULTEPRODUIT_H
#define CONSULTEPRODUIT_H

int argc;
char **argv;
char *email;
void onDestroyConpro(GtkWidget *pwindow ,gpointer data);
void Consulteproduit(int argc,char **argv);
static gboolean onClickConpro( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // CONSULTEPRODUIT_H
