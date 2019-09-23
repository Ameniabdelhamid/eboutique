#ifndef CONSULTECLIENT_H
#define CONSULTECLIENT_H

int argc;
char **argv;
char *email;
void onDestroyConC(GtkWidget *pwindow ,gpointer data);
void ConsulteClient(int argc,char **argv);
static gboolean onClickConC( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // CONSULTECLIENT_H
