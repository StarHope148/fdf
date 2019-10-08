# Fdf

LINKING MinilibX on BSD/Linux and X-Window To use MiniLibX functions, you'll need to link your software with several libraries, including the MiniLibX library itself. To do this, simply add the following arguments at linking time:

-lmlx -lXext -lX11

You may also need to specify the path to these libraries, using the -L flag.