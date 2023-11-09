#include <gtk/gtk.h>

// Define the Sudoku grid as a 9x9 2D array
int sudoku_grid[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Create a 9x9 grid of Entry widgets for the Sudoku board
GtkWidget* entries[9][9];

// Function to initialize the Sudoku grid
void initialize_sudoku(GtkWidget *window) {
    GtkWidget *grid;
    grid = gtk_grid_new();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            entries[i][j] = gtk_entry_new();
            gtk_entry_set_max_length(GTK_ENTRY(entries[i][j]), 1);
            gtk_grid_attach(GTK_GRID(grid), entries[i][j], j, i, 1, 1);
            
            // Add grid lines (spacing) to mimic a Sudoku board
            GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
            if (j % 3 == 2 && j != 8) {
                gtk_grid_attach(GTK_GRID(grid), separator, j + 1, i, 1, 1);
            }
        }

        // Add horizontal lines (spacing) to mimic a Sudoku board
        GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
        if (i % 3 == 2 && i != 8) {
            for (int j = 0; j < 9; j++) {
                gtk_grid_attach(GTK_GRID(grid), separator, j, i + 1, 1, 1);
            }
        }
    }

    gtk_container_add(GTK_CONTAINER(window), grid);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sudoku Solver");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    initialize_sudoku(window);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
