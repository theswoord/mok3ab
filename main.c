#include "cube3d.h"

// void animation_init(t_cube *cube) // for bonus
// {
//     cube->anim[0] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./blood.png"));
//     cube->anim[1] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./dry.png"));

// }

// void *animations_draw(t_cube *cube) // an7yedhom
// {
//     int i = 0;
//     while (1)
//     {
//         /* code */
//         if (i == 600)
//         {
//             printf("%d\n",i);
//             mlx_image_to_window(cube->window->mlx,cube->anim[0],500,500);
//             // mlx_delete_image(cube->window->mlx,cube->anim[0]);

//             mlx_image_to_window(cube->window->mlx,cube->anim[1],500,500);
//             // cube->anim[0] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./blood.png"));
//             // cube->anim[1] = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./dry.png"));

//     //         /* code */
//         }
//         // sleep(1);
//             // mlx_image_to_window(cube->window->mlx,cube->anim[1],500,500);

//         if(i == 1800)
//             i=0;
//         i++;
//     }
//     return NULL;
// }
void texture_set(t_cube *cube)
{
    cube->colors->EA = extract_color(cube->drawings->EA, cube->colors->dim); // 1
    cube->colors->NO = extract_color(cube->drawings->NO, cube->colors->dim); // 2
    cube->colors->WE = extract_color(cube->drawings->WE, cube->colors->dim); // 3
    cube->colors->SO = extract_color(cube->drawings->SO, cube->colors->dim); // 4
    // printf("%p %p %p %p\n",cube->drawings->NO,cube->drawings->SO,cube->drawings->EA,cube->drawings->WE);
    // printf("%p %p %p %p\n",cube->colors->NO,cube->colors->SO,cube->colors->EA,cube->colors->WE);
};

unsigned long *extract_color(mlx_texture_t *texture, int *arr)
{
    int i = 0;
    int j = 0;
    static int k;
    int total = texture->height * texture->width;
    unsigned long *tmp = malloc((texture->height * texture->width) * sizeof(unsigned long));
    // printf("wtf%p \n",tmp);

    // while (k < 8)
    // {
    arr[k] = texture->height;
    arr[k + 1] = texture->width;
    k += 2;
    // }

    // if (!tmp)
    // {
    //     fprintf(stderr, "Failed to allocate memory\n");
    //     exit(EXIT_FAILURE);
    // }
    while (i < total)
    {
        // j++;
        // if (/* condition */)
        // {
        //     /* code */
        // }

        tmp[i] = (texture->pixels[j] << 24) | (texture->pixels[j + 1] << 16) | (texture->pixels[j + 2] << 8) | (texture->pixels[j + 3]);
        // printf("%d %d %d %d\n", texture->pixels[j],texture->pixels[j+1],texture->pixels[j+2],texture->pixels[j+3]);
        j += texture->bytes_per_pixel;
        i++;
    }
    // mlx_delete_texture(texture);
    return (tmp);
}

void init_mlx(t_cube *cube)
{
    cube->window->mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);
    cube->window->img = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
    cube->mini_map = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
    cube->walls = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);   // this is temporary
    mlx_image_to_window(cube->window->mlx, cube->window->img, 0, 0); // put img ptr on the window
    // mlx_image_to_window(cube->window->mlx, cube->mini_map,50,50);
    mlx_image_to_window(cube->window->mlx, cube->mini_map, 0, 0);
    // mlx_image_to_window(cube->window->mlx, cube->walls, 0, 0); // here

    // cube->mini_map = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./blood.png")); // test image fo9 image hh
}

void set_background(t_cube *cube)
{
    //  unsigned long floor
    cube->colors->finalfloor = (cube->colors->F[0] << 24) | (cube->colors->F[1] << 16) | (cube->colors->F[2] << 8) | 0xFF; // hadi parsing dial color;
    cube->colors->finalceil = (cube->colors->C[0] << 24) | (cube->colors->C[1] << 16) | (cube->colors->C[2] << 8) | 0xFF;  // hadi parsing dial color;
}

void draw_background(mlx_image_t *img, t_cube *cube)
{
    // mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);

    // img = mlx_new_image(mlx,WIDTH,HEIGHT);
    // mlx_image_to_window(mlx,)
    // mlx_pn

    // hh = mlx_load_png("./blood.png");
    // hhhh = mlx_texture_to_image(mlx, hh);
    int x = 0;
    int y = 0;
    // printf("%d,%d,%d\n",cube->colors.F[0],cube->colors.F[1],cube->colors.F[2]);
    // printf("%d,%d,%d\n",cube->colors.C[0],cube->colors.C[1],cube->colors.C[2]);
    // set_background(cube);
    // unsigned long floor = (cube->colors.F[0] << 24) | (cube->colors.F[1] << 16) | (cube->colors.F[2] << 8) | 0xFF; // hadi parsing dial color;
    // unsigned long s9ef = (cube->colors.C[0] << 24) | (cube->colors.C[1] << 16) | (cube->colors.C[2] << 8) | 0xFF;  // hadi parsing dial color;

    // printf("l3rd %d , lines %d \n",WIDTH,HEIGHT);
    while (x < WIDTH)
    {
        while (y < HEIGHT / 2)
        {
            // printf("%d %d\n",x,y);
            mlx_put_pixel(img, x, y, cube->colors->finalceil);
            y++;
        }
        while (y < HEIGHT)
        {
            mlx_put_pixel(img, x, y, cube->colors->finalfloor);
            y++;
        }

        y = 0;
        x++;
    }
    // mlx_
    // hh.
    // hhj =  mlx_new_image(mlx,100,100);
    // mlx_put_string(mlx,"asdkfjlaksfjklas", 90 ,100);
    // // mlx_image_to_window(mlx , hh ,300,300);
    // mlx_image_to_window(mlx , hh,100,100);
    // // mlx_put_pixel()
}
void map_divider(char *textures, char *background, char *map, t_cube *cube)
{
    cube->background = ft_split(background, '\n');
    free(background);
    cube->textures = ft_split(textures, '\n');
    free(textures);
    // printf("%s\n",map);
    cube->map = ft_split(map, '\n');
    free(map);
    // print_tableau(cube->map);
}
void parse(t_cube *cube)
{
    int i = 0;
    while (cube->background[i])
    {

        rgb_parse(cube->background[i], cube);
        i++;
        /* code */
    }
    set_background(cube);
}
void set_rgb(char **tab, t_cube *cube, char what)
{
    int i = 0;
    while (tab[i])
    {
        /* code */
        if (what == 'F')
        {
            // printf("f S %s\n", tab[i]);
            cube->colors->F[i] = ft_atoi(tab[i]); // hna ba9i check dial 255 < o > 0 o 3adad les i ila kan >3 err
            // printf("F %d\n",cube->colors.F[i]);
            /* code */
        }
        if (what == 'C')
        {
            cube->colors->C[i] = ft_atoi(tab[i]); // hna ba9i check dial 255 < o > 0 o 3adad les i ila kan >3 err
            // printf("C %d\n",cube->colors.C[i]);

            /* code */
        }
        i++;
    }
}
void rgb_parse(char *str, t_cube *cube)
{
    // str = ft_strtrim(str, " \t");
    int i = 0;
    // char what ;
    int is_floor = 0;
    int is_ceilling = 0;
    char what;
    char **work = NULL;
    char *tmp = NULL;
    // found_after_space(str,'F');
    if (found_after_space(str, 'F') == true)
    {
        tmp = ft_strtrim(str, " \tF");
        free(str);
        what = 'F';
    }
    else if (found_after_space(str, 'C') == true)
    {
        tmp = ft_strtrim(str, " \tC");
        free(str);
        what = 'C';
    }
    // what =
    work = ft_split(tmp, ',');
    free(tmp);
    set_rgb(work, cube, what); // check before set
    free_tableau(work);
    // while (str[i])
    // {
    //     // if (str[i] == '')
    //     // {
    //     //     /* code */
    //     // }

    //     i++;
    //     /* code */
    // }
}

void read_map(int fd, t_cube *cube)
{

    char *textures = NULL;
    char *background = NULL;
    char *map = NULL;

    char *line = get_next_line(fd);

    while (line)
    {
        // longline
        if (found_after_space(line, 'F') || found_after_space(line, 'C'))
        {
            background = ft_strjoingnl(background, line);
            free(line);
            /* code */
        }
        else if (found_after_space(line, 'N') || found_after_space(line, 'S') || found_after_space(line, 'W') || found_after_space(line, 'E'))
        {
            textures = ft_strjoingnl(textures, line);
            free(line);
            /* code */
        }
        else if (found_after_space(line, '1'))
        {
            // printf("%s, %d\n",line , ft_strlen(line));
            map = ft_strjoingnl(map, line);
            free(line);
            /* code */
        }
        else
        {
            free(line);
        }
        line = get_next_line(fd);
    }
    map_divider(textures, background, map, cube);
    // return line;
}

int main(int ac, char **av)
{
    t_cube *cube = (t_cube *)malloc(sizeof(t_cube));
    ft_memset(cube, 0, sizeof(t_cube));
    cube->window = (t_win *)malloc(sizeof(t_win));
    ft_memset(cube, 0, sizeof(t_win));

    cube->colors = (t_colors *)malloc(sizeof(t_colors));
    ft_memset(cube, 0, sizeof(t_colors));

    cube->drawings = (t_textures *)malloc(sizeof(t_textures));
    ft_memset(cube, 0, sizeof(t_textures));

    int fd = open(av[1], O_RDONLY);
    read_map(fd, cube);
    print_tableau(cube->textures);
    parse(cube);
    parse_textures(cube);
    // printf("%p %p %p %p\n",cube->drawings->NO,cube->drawings->SO,cube->drawings->EA,cube->drawings->WE);

    texture_set(cube);

    init_mlx(cube);

    fill_map(cube);
    // mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);
    // img = mlx_new_image(mlx, WIDTH, HEIGHT);
    // printf("ZABY\n");
    draw_background(cube->window->img, cube); // made the imgptr
    mini_map_draw(cube);
    // mlx_delete_image(cube->window->mlx, cube->mini_map); // hadi ach nkhdm ghir f walls
    cube->v3.deltax = cos(cube->v3.angle) * 5.0; // speed
    cube->v3.deltay = sin(cube->v3.angle) * 5.0; // speed
    printf("%f , %f\n", cube->v3.angle, P2);
// cube->v3.angle += 2.5;
    // for (size_t i = 0; i < 8; i++)
    // {
    //     printf("%d ",cube->colors->dim[i]);
    //     // if (i % 2 == 0)
    //     // {
    //     //     printf ("EA NO WE SO");
    //     //     /* code */
    //     // }

    // }
    // printf("%d\n",height_extract(cube,"EA"));
    // animation_init(&cube); // memes
    // mlx_loop_hook(cube.window->mlx,animations_draw,&cube);
    // mlx_loop_hook(cube.window->mlx,pressed,&cube);

    // cube->win.planeX = 0.66;
    // cube->win.planeY = 0.0;
    // castingv2(cube);

    mlx_loop_hook(cube->window->mlx, &pressed, cube);
    // mlx_key_hook(cube->window->mlx,&pressed,cube);
    mlx_loop(cube->window->mlx);
    mlx_terminate(cube->window->mlx);
    return 0;
}



double horizontal(t_cube *cube)
{
    // cube->v3.rayangle = cube->v3.angle;
    double tanges;
    int mapy;
    int mapx;
    tanges = -1 / tan(cube->v3.rayangle);
    // printf("%f %f\n", cube->v3.rayangle, tanges);
    if (cube->v3.rayangle > M_PI)
    {
        cube->v3.rayy = ((int)cube->player.y / MINIBLOCK * MINIBLOCK) - 0.0001; // 7yedt cast o ba9a r3da
        // printf("%f\n", cube->v3.rayy);
        cube->v3.rayx = ((int)cube->player.y - cube->v3.rayy) * tanges + (int)cube->player.x; // 7yedt cast o ba9a r3da
        cube->v3.yoffset = -MINIBLOCK;
        cube->v3.xoffset = -cube->v3.yoffset * tanges;
    }
    if (cube->v3.rayangle < M_PI)
    {
        cube->v3.rayy = ((int)cube->player.y / MINIBLOCK) * MINIBLOCK + MINIBLOCK; // 7yedt cast o ba9a r3da
        cube->v3.rayx = ((int)cube->player.y - cube->v3.rayy) * tanges + (int)cube->player.x; // 7yedt cast o ba9a r3da
        cube->v3.yoffset = MINIBLOCK;
        cube->v3.xoffset = -cube->v3.yoffset * tanges;
    }
    if (cube->v3.rayangle == 0)
    {
        // cube->v3.rayx = cube->player.x;
        cube->v3.xoffset = MINIBLOCK;
        // cube->v3.rayy = cube->player.y;
    }
    if (cube->v3.rayangle == M_PI)
    {
        // cube->v3.rayx = cube->player.x;
        cube->v3.xoffset = -MINIBLOCK;
        // cube->v3.rayy = cube->player.y;
    }
    // printf("ha1\n");

    while (1)
    {

        mapy = (int)cube->v3.rayy / MINIBLOCK;
        mapx = (int)cube->v3.rayx / MINIBLOCK;
        // printf("mapx = %d  mapy= %d maxx %d maxy %d\n",mapx,mapy, cube->map_stuff.max ,cube->map_stuff.lines);
        if ((mapy >= cube->map_stuff.lines || mapx >= cube->map_stuff.max) || (mapy <= 0 || mapx <= 0) || cube->map[mapy][mapx] == '1')
        {

            break;
        }
        else
        {
            // printf("map %d \n", mapy);

            // printf("%f\n", cube->v3.rayy);

            // printf("hh\n");
            // printf("y= %f  x= %f\n",cube->v3.yoffset,cube->v3.xoffset);
            if (cube->v3.rayy < HEIGHT && cube->v3.rayy > 0)
            {
                cube->v3.rayy += cube->v3.yoffset;
                /* code */
            }
            else
                return (999998897897897);
            if (cube->v3.rayx < WIDTH && cube->v3.rayx > 0)
            {
                /* code */
                cube->v3.rayx += cube->v3.xoffset;
            }
            else
                return (999998897897897);
        }
    }
    cube->v3.Hx = cube->v3.rayx;
    cube->v3.Hy = cube->v3.rayy;

    return (sqrt(pow(cube->v3.Hx - cube->player.x, 2) + pow(cube->v3.Hy - cube->player.y, 2))); // sqrt if i need distance;
                                                                                                // printf("ha2\n");

    //         cube->dda.startx = cube->player.x;
    //     cube->dda.starty = cube->player.y;
    //     cube->dda.endx = cube->v3.rayx;
    //     cube->dda.endy = cube->v3.rayy;
    // ddanalizer(cube->mini_map, cube, 0x00FF00FF);
    // printf("ha2\n");
    // return 0;
}
double vertical(t_cube *cube)
{
    double tanges;
    int mapy;
    int mapx;
    tanges = -tan(cube->v3.rayangle);
    // printf("h%f %fh\n",tanges,cube->v3.rayangle );
    if (cube->v3.rayangle > P2 && cube->v3.rayangle < P3)
    {
        cube->v3.rayx = ((int)cube->player.x / MINIBLOCK) * MINIBLOCK - 0.0001;
        cube->v3.rayy = ((int)cube->player.x - cube->v3.rayx) * tanges + (int)cube->player.y;
        cube->v3.xoffset = -MINIBLOCK;
        cube->v3.yoffset = -cube->v3.xoffset * tanges;
    }
    if (cube->v3.rayangle < P2 || cube->v3.rayangle > P3)
    {
        cube->v3.rayx = ((int)cube->player.x / MINIBLOCK * MINIBLOCK) + MINIBLOCK;
        cube->v3.rayy = ((int)cube->player.x - cube->v3.rayx) * tanges + (int)cube->player.y;
        cube->v3.xoffset = MINIBLOCK;
        cube->v3.yoffset = -cube->v3.xoffset * tanges;
    }
    if (cube->v3.rayangle == P2)
    {
        // cube->v3.rayx = (int)cube->player.x;
        cube->v3.yoffset = MINIBLOCK;
        // cube->v3.rayy = (int)cube->player.y;
    }
    if (cube->v3.rayangle == P3)
    {
        // cube->v3.rayx = (int)cube->player.x;
        cube->v3.yoffset = -MINIBLOCK;
        // cube->v3.rayy = (int)cube->player.y;
    }
    while (1)
    {
        mapy = (int)cube->v3.rayy / MINIBLOCK;
        mapx = (int)cube->v3.rayx / MINIBLOCK;
        // printf("x = %d y =  %d     %d %d\n", mapx, mapy, cube->map_stuff.max, cube->map_stuff.lines);
        if ((mapy >= cube->map_stuff.lines || mapx >= cube->map_stuff.max) || (mapy <= 0 || mapx <= 0) || cube->map[mapy][mapx] == '1')
        {

            // printf("fdfdf\n");
            break;
        }
        else
        {
            if (cube->v3.rayy < HEIGHT && cube->v3.rayy > 0)
            {
                cube->v3.rayy += cube->v3.yoffset;
                /* code */
            }
            else
                return (999998897897897);
            if (cube->v3.rayx < WIDTH && cube->v3.rayx > 0)
            {
                /* code */
                cube->v3.rayx += cube->v3.xoffset;
            }
            else
                return (999998897897897);
            // cube->v3.rayy += cube->v3.yoffset;
            // cube->v3.rayx += cube->v3.xoffset;
        }
    }
    cube->v3.Vx = cube->v3.rayx;
    cube->v3.Vy = cube->v3.rayy;

    return (sqrt(pow(cube->v3.Vx - cube->player.x, 2) + pow(cube->v3.Vy - cube->player.y, 2)));
    // return 0;
}
void cast_v3(t_cube *cube)
{
    // printf("x %f y %f\n", cube->player.x,cube->player.y);
    int i = 0;
    // cube->v3.angle += 0.01;
    cube->v3.rayangle = cube->v3.angle - WIDTH / 2.0 * RAD;
    // cube->v3.rayangle += 1.01;

    // printf("%f %f \n",cube->v3.rayangle , cube->v3.angle);
    draw_player(cube, 1);
    draw_background(cube->window->img, cube);
    // printf("%f %f\n",cube->player.x,cube->player.y);
    while (i <= WIDTH)
    {

        if (cube->v3.rayangle < 0)
            cube->v3.rayangle += 2 * M_PI;
        if (cube->v3.rayangle >= 2 * M_PI)
            cube->v3.rayangle -= 2 * M_PI;
        double dH;
        dH = horizontal(cube);
        double dV;
        dV = vertical(cube);
    // printf("hh %f %f\n",cube->player.x,cube->player.y);

        cube->v3.wallheight = (HEIGHT * MINIBLOCK) / cube->v3.distance;

        if (cube->v3.wallheight > HEIGHT)
        {
            cube->v3.wallheight = HEIGHT;
        }

        if (dH < dV)
        {
            cube->v3.distance = dH;
            cube->dda.startx = cube->player.x;
            cube->dda.starty = cube->player.y;
            cube->dda.endx = cube->v3.Hx;
            cube->dda.endy = cube->v3.Hy;
            ddanalizer(cube->mini_map, cube, 0x00FFFFFF);

            cube->v3.side = 0;
        }
        else
        {
            cube->v3.distance = dV;
            cube->dda.startx = cube->player.x;
            cube->dda.starty = cube->player.y;
            cube->dda.endx = cube->v3.Vx;
            cube->dda.endy = cube->v3.Vy;
            ddanalizer(cube->mini_map, cube, 0x0000FFFF);

            cube->v3.side = 1;
        }
        double ca = cube->v3.angle - cube->v3.rayangle;

        if (ca <= 0)
            ca += 2 * M_PI;
        if (ca >= 2 * M_PI)
            ca -= 2 * M_PI;
        cube->v3.distance = cube->v3.distance * cos(ca); // fisheye

        cube->dda.startx = i;
        cube->dda.starty = HEIGHT / 2 - cube->v3.wallheight / 2;
        cube->dda.endx = i;
        cube->dda.endy = cube->v3.wallheight / 2 + HEIGHT / 2;

        cube->v3.rayangle += RAD;

        draw_textures(cube->window->img, cube);

        i++;
    }
}

void draw_textures(mlx_image_t *img, t_cube *cube)
{

    int color;
    int i = 0;
    if (cube->v3.side == 0)
    {
        if (cube->v3.rayangle < M_PI) // SO
        {
            // printf("%d\n", factor_finder(cube,"SO"));
            // textured(img, cube,cube->colors->SO,factor_finder(cube,"SO"));
            dakh(img,cube,cube->colors->SO,32,32,factor_finder(cube,"SO"));
            // ddanalizer(img, cube, 0xFF0000AA);
            // txtv3(cube->window->img, cube, cube->colors->SO, cube->dda.startx,cube->dda.starty);
        }
        else // NO
        {
            dakh(img,cube,cube->colors->NO,32,32,factor_finder(cube,"NO"));
            // tabta(img, cube,cube->colors->NO,factor_finder(cube,"NO"));
            // textured(img, cube,cube->colors->NO,factor_finder(cube,"NO"));

            // ddanalizer(img, cube, 0x0000FFAA);
            // txtv3(cube->window->img, cube, cube->colors->NO, cube->dda.startx, cube->dda.starty);
        }
    }
    else
    {
        if (cube->v3.rayangle > P3 || cube->v3.rayangle < P2) // EA
        {
            // textured(img, cube,cube->colors->EA);
            dakh(img,cube,cube->colors->EA,32,32,factor_finder(cube,"EA"));
            // textured(img, cube,cube->colors->EA,factor_finder(cube,"EA"));

            // ddanalizer(img, cube, 0xFFFF00AA);
            // txtv3(cube->window->img, cube, cube->colors->WE, cube->dda.startx, cube->dda.starty);
        }
        else // WE
        {
            dakh(img,cube,cube->colors->WE,32,32,factor_finder(cube,"WE"));
            // textured(img, cube,cube->colors->WE,factor_finder(cube,"WE"));

            // ddanalizer(img, cube, 0x00FF00AA);
            // txtv3(cube->window->img, cube, cube->colors->SO, cube->dda.startx, cube->dda.starty);
        }
    }
}