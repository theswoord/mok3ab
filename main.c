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
    cube->colors.EA = extract_color(cube->drawings.EA);
    cube->colors.SO = extract_color(cube->drawings.SO);
    cube->colors.NO = extract_color(cube->drawings.NO);
    cube->colors.WE = extract_color(cube->drawings.WE);
};

unsigned long *extract_color(mlx_texture_t *texture)
{
    int i = 0;
    int j = 0;
    int total = texture->height * texture->width * texture->bytes_per_pixel;
    unsigned long *tmp = malloc((texture->height * texture->width) * sizeof(unsigned long));
    if (!tmp)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    while (i < total)
    {
        // j++;
        // if (/* condition */)
        // {
        //     /* code */
        // }

        tmp[i] = (texture->pixels[j] << 24) | (texture->pixels[j + 1] << 16) | (texture->pixels[j + 2] << 8) | (texture->pixels[j + 3]);
        j += texture->bytes_per_pixel;
        i++;
    }
    mlx_delete_texture(texture);
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
    cube->colors.finalfloor = (cube->colors.F[0] << 24) | (cube->colors.F[1] << 16) | (cube->colors.F[2] << 8) | 0xFF; // hadi parsing dial color;
    cube->colors.finalceil = (cube->colors.C[0] << 24) | (cube->colors.C[1] << 16) | (cube->colors.C[2] << 8) | 0xFF;  // hadi parsing dial color;
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
            mlx_put_pixel(img, x, y, cube->colors.finalceil);
            y++;
        }
        while (y < HEIGHT)
        {
            mlx_put_pixel(img, x, y, cube->colors.finalfloor);
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
            cube->colors.F[i] = ft_atoi(tab[i]); // hna ba9i check dial 255 < o > 0 o 3adad les i ila kan >3 err
            // printf("F %d\n",cube->colors.F[i]);
            /* code */
        }
        if (what == 'C')
        {
            cube->colors.C[i] = ft_atoi(tab[i]); // hna ba9i check dial 255 < o > 0 o 3adad les i ila kan >3 err
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
    cube->window = malloc(sizeof(t_win));
    int fd = open(av[1], O_RDONLY);
    read_map(fd, cube);
    print_tableau(cube->textures);
    parse(cube);
    parse_textures(cube);
    texture_set(cube);

    init_mlx(cube);

    fill_map(cube);
    // mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);
    // img = mlx_new_image(mlx, WIDTH, HEIGHT);
    // printf("ZABY\n");
    draw_background(cube->window->img, cube); // made the imgptr
    mini_map_draw(cube);
    mlx_delete_image(cube->window->mlx, cube->mini_map); // hadi ach nkhdm ghir f walls
    cube->v3.deltax = cos(cube->v3.angle) * 5;           // speed
    cube->v3.deltay = sin(cube->v3.angle) * 5;           // speed
    printf("%f , %f\n", cube->v3.angle, P2);

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

void castingv2(t_cube *cube)
{
    int x = 0;
    double stepX;
    double stepY;
    int side; // was a NS or a EW wall hit?
    double perpWallDist;

    // printf("%f\n", atan((cube->win.planeY/1.0)*(M_PI/180)));
    img_clear(cube->window->img, WIDTH, HEIGHT);

    while (x < WIDTH)
    {
        cube->win.cameraX = 2.0 * x / (double)(WIDTH)-1;

        cube->win.RaydirecX = cube->win.dirX + cube->win.planeX * cube->win.cameraX;
        cube->win.RaydirecY = cube->win.dirY + cube->win.planeY * cube->win.cameraX;
        cube->win.posinmapX = cube->player.x / (int)MINIBLOCK;
        cube->win.posinmapY = cube->player.y / (int)MINIBLOCK;
        // printf("fin ghadi x %f fin ghadi y  %f %f\n", cube->win.dirX, cube->win.dirY , pow(cube->win.dirX,2)+pow(cube->win.dirY,2) );
        // printf("%d %d %d %d \n",cube->player.x,cube->player.y,cube->win.posinmapX,cube->win.posinmapY);
        // pr
        // printf("%f %f\n",cube->win.RaydirecX,cube->win.RaydirecY);

        cube->win.deltaDistX = fabs(1 / cube->win.RaydirecX);

        cube->win.deltaDistY = fabs(1 / cube->win.RaydirecY);

        // printf("ray x%f ray Y %f elx %f del y%f\n", cube->win.RaydirecX,cube->win.RaydirecY,cube->win.deltaDistX, cube->win.deltaDistY);
        if (cube->win.RaydirecX < 0)
        {
            stepX = -1;
            cube->win.sideDistX = ((cube->player.x / MINIBLOCK) - cube->win.posinmapX) * cube->win.deltaDistX;
        }
        else
        {
            stepX = 1;
            cube->win.sideDistX = ((cube->player.x / MINIBLOCK) - cube->win.posinmapX) * cube->win.deltaDistX;
        }
        if (cube->win.RaydirecY < 0)
        {
            stepY = -1;
            cube->win.sideDistY = ((cube->player.y / MINIBLOCK) - cube->win.posinmapY) * cube->win.deltaDistY;
        }
        else
        {
            stepY = 1;
            cube->win.sideDistY = ((cube->player.y / MINIBLOCK) - cube->win.posinmapY) * cube->win.deltaDistY;
        }
        int hit = 0;
        //   printf("%f\n",cube->win.cameraX);
        while (hit == 0)
        {
            // jump to next map square, either in x-direction, or in y-direction
            if (cube->win.sideDistX < cube->win.sideDistY)
            {
                cube->win.sideDistX += cube->win.deltaDistX;
                cube->win.posinmapX += stepX;
                side = 0;
            }
            else
            {
                cube->win.sideDistY += cube->win.deltaDistY;
                cube->win.posinmapY += stepY;
                side = 1;
            }

            // printf("%f %f , st")
            // printf("%f %d %f %d\n",cube->win.sideDistX,cube->win.posinmapX ,cube->win.sideDistY ,cube->win.posinmapY);
            // Check if ray has hit a wall
            // printf("%d %d %c \n", cube->win.posinmapY, cube->win.posinmapX ,cube->map[cube->win.posinmapY][cube->win.posinmapX]);
            if (side == 0)
                perpWallDist = (cube->win.sideDistX - cube->win.deltaDistX);
            else
                perpWallDist = (cube->win.sideDistY - cube->win.deltaDistY);
            double wallX; // where exactly the wall was hit
            if (side == 0)
                wallX = cube->player.y / 32 + perpWallDist * cube->win.RaydirecY;
            else
                wallX = cube->player.x / 32 + perpWallDist * cube->win.RaydirecX;
            wallX -= floor((wallX));
            cube->dda.startx = cube->player.x;
            cube->dda.starty = cube->player.y;
            cube->dda.endx = ((cube->win.posinmapX * 32 + wallX * 32));
            cube->dda.endy = ((cube->win.posinmapY * 32) + 32 * (1 - stepY) / 2);
            // printf("end %f %f\n",cube->dda.endx,cube->dda.endy );
            // printf("%d")
            // printf("%d\n", x);
            // printf("sdX %f sdY %f posX %d posY %d \n", cube->win.sideDistX , cube->win.sideDistY,cube->win.posinmapX*32,cube->win.posinmapY*32 );
            // printf("sx %d sy %d ex %d ey %d \n", cube->dda.startx,cube->dda.starty,cube->dda.endx,cube->dda.endy);
            if (cube->map[cube->win.posinmapY][cube->win.posinmapX] == '1')
            {
                // ddanalizer(cube->mini_map,cube);
                // cube->dda.startx =
                ddanalizer(cube->mini_map, cube, 0xFF0000FF);
                // printf("kk\n");
                hit = 1; // an7bs 7d hnaya
            }
        }
        // Calculate height of line to draw on screen
        int lineHeight = (int)(HEIGHT / perpWallDist);
        // calculate lowest and highest pixel to fill in current stripe
        int pitch = 100;

        int drawStart = (-lineHeight / 2) + (HEIGHT / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (HEIGHT / 2);
        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT - 1;

        // printf("%f\n", wallX*32);

        //   unsigned long color = cube->colors.NO[k];
        int k = 0;
        int l = 0;

        cube->dda.color = 0x00FF00FF;

        cube->dda.startx = x;
        cube->dda.starty = drawStart;
        cube->dda.endx = x;
        cube->dda.endy = drawEnd;
        if (side == 1)
        {
            cube->dda.color = 0xFFAA0FFF;
        }
        // while (k < 32)
        // {
        //     /* code */
        // textured(cube->window->img, cube, cube->colors.SO);
        //     k++;
        // }

        ddanalizer(cube->window->img, cube, cube->dda.color);
        // mlx_put_pixel()

        x++;
    }
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
        cube->v3.rayy = floor(((cube->player.y / MINIBLOCK) * MINIBLOCK)) - 0.001;
        // printf("%f\n", cube->v3.rayy);
        cube->v3.rayx = (cube->player.y - cube->v3.rayy) * tanges + cube->player.x;
        cube->v3.yoffset = -MINIBLOCK;
        cube->v3.xoffset = -cube->v3.yoffset * tanges;
    }
    if (cube->v3.rayangle < M_PI)
    {
        cube->v3.rayy = (int)((cube->player.y / MINIBLOCK) * MINIBLOCK) + MINIBLOCK;
        cube->v3.rayx = (cube->player.y - cube->v3.rayy) * tanges + cube->player.x;
        cube->v3.yoffset = MINIBLOCK;
        cube->v3.xoffset = -cube->v3.yoffset * tanges;
    }
    if (cube->v3.rayangle == 0)
    {
        cube->v3.rayx = cube->player.x;
        cube->v3.xoffset = MINIBLOCK;
        cube->v3.rayy = cube->player.y;
    }
    if (cube->v3.rayangle == M_PI)
    {
        cube->v3.rayx = cube->player.x;
        cube->v3.xoffset = -MINIBLOCK;
        cube->v3.rayy = cube->player.y;
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

    return (sqrtf(pow(cube->v3.Hx - cube->player.x, 2) + pow(cube->v3.Hy - cube->player.y, 2))); // sqrt if i need distance;
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
        cube->v3.rayx = floor((cube->player.x / MINIBLOCK) * MINIBLOCK) - 0.001;
        cube->v3.rayy = (cube->player.x - cube->v3.rayx) * tanges + cube->player.y;
        cube->v3.xoffset = -MINIBLOCK;
        cube->v3.yoffset = -cube->v3.xoffset * tanges;
    }
    if (cube->v3.rayangle < P2 || cube->v3.rayangle > P3)
    {
        cube->v3.rayx = (int)((cube->player.x / MINIBLOCK) * MINIBLOCK) + MINIBLOCK;
        cube->v3.rayy = (cube->player.x - cube->v3.rayx) * tanges + cube->player.y;
        cube->v3.xoffset = MINIBLOCK;
        cube->v3.yoffset = -cube->v3.xoffset * tanges;
    }
    if (cube->v3.rayangle == P2)
    {
        cube->v3.rayx = cube->player.x;
        cube->v3.yoffset = MINIBLOCK;
        cube->v3.rayy = cube->player.y;
    }
    if (cube->v3.rayangle == P3)
    {
        cube->v3.rayx = cube->player.x;
        cube->v3.yoffset = -MINIBLOCK;
        cube->v3.rayy = cube->player.y;
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

    return (sqrtf(pow(cube->v3.Vx - cube->player.x, 2) + pow(cube->v3.Vy - cube->player.y, 2)));
    // return 0;
}
void cast_v3(t_cube *cube)
{
    int color = 0xFFFFFFFF;
    float i = 0;
    float tanges;
    cube->v3.rayangle = cube->v3.angle - FOV / 2 * RAD;
    // double viewangle = cube->v3.angle;
    // printf("%f\n", cube->v3.rayangle );
    int mapx;
    int mapy;
    // img_clear(cube->window->img,WIDTH,HEIGHT);
    draw_background(cube->window->img, cube);
    //     cube->dda.startx = cube->player.x;
    // cube->dda.starty = cube->player.y;
    // cube->dda.endx = cube->player.x + cube->v3.deltax * 5;
    // cube->dda.endy = cube->player.y + cube->v3.deltay*5;
    // ddanalizer(cube->mini_map, cube, 0xFFFF00FF);
    while (i < FOV)
    {
        cube->v3.rayangle += RAD;
        if (cube->v3.rayangle < 0)
        {
            cube->v3.rayangle += 2 * M_PI;
        }
        if (cube->v3.rayangle >= 2 * M_PI)
        {
            cube->v3.rayangle -= 2 * M_PI;
        }
        double dH = horizontal(cube);
        double dV = vertical(cube);

        // printf("%f %f\n" , cube->v3.rayangle , cube->v3.angle);
        cube->v3.wallheight = (HEIGHT * MINIBLOCK) / cube->v3.distance;

        if (cube->v3.wallheight > HEIGHT)
        {
            cube->v3.wallheight = HEIGHT;
        }
        float lineOffset = WIDTH - cube->v3.wallheight / 2;

        if (dH < dV)
        {
            cube->v3.distance = dH;
            cube->v3.side = 0;
        }
        else
        {
            cube->v3.distance = dV;
            cube->v3.side = 1;
        }
        cube->dda.startx = i;
        cube->dda.starty = HEIGHT / 4;
        cube->dda.endx = i;
        cube->dda.endy = cube->v3.wallheight + HEIGHT / 4;
        draw_textures(cube->window->img, cube);
        // draw_rec(cube->window->img,cube,4, 0xFFFF00FF);
        i++;
    }

    // draw_player(cube, 0);
    // draw_background(cube->window->img, cube);
}

// void fix
void draw_textures(mlx_image_t *img, t_cube *cube)
{

    int color;
    int i = 0;
    if (cube->v3.side == 0)
    {
        // while (i < 32)
        // {
        //     /* code */
        //     color = cube->colors.NO[0];
        if (cube->v3.rayangle < M_PI)
        {
            // ddanalizer(img, cube, 0xFF0000FF);
            textured(img, cube,cube->colors.SO);

            /* code */
        }
        else
            // ddanalizer(img, cube, 0x0000FFFF);
            textured(img, cube,cube->colors.WE);

        //     // printf("%d\n",cube->colors.NO[i]);
        //     i++;
        // }
        // i = 0;
        // color = 0xFF00FFFF;
        /* code */
        // textured(img, cube,cube->colors.NO);
        // ddanalizer(img,cube,0xFF0000FF);
    }
    else
    {
        // color = 0x00FFFF;
        if (cube->v3.rayangle > P3 || cube->v3.rayangle < P2)
        {
            textured(img, cube,cube->colors.EA);

            // ddanalizer(img, cube, 0xFFFF00FF);

            /* code */
        }
        else
            // ddanalizer(img, cube, 0x00FF00FF);
            textured(img, cube,cube->colors.NO);

        // ddanalizer(img,cube,0x00FF00FF);
    }

    // textured(img, cube, color);
}