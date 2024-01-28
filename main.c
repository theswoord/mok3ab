#include "cube3d.h"

void texture_set(t_cube *cube)
{
    int i = 0;
    cube->colors->EA = extract_color(cube->drawings->EA, cube->colors->dim); // 1
    cube->colors->NO = extract_color(cube->drawings->NO, cube->colors->dim); // 2
    cube->colors->WE = extract_color(cube->drawings->WE, cube->colors->dim); // 3
    cube->colors->SO = extract_color(cube->drawings->SO, cube->colors->dim); // 4
    while (i < 8)
    {
        if (cube->colors->dim[i] != 32)
        {
            printf("Error : more or less than 32 bit\n");
            exit(1);
        }
        i++;
    }
}

unsigned long *extract_color(mlx_texture_t *texture, int *arr)
{
    int i = 0;
    int j = 0;
    static int k;
    int total = texture->height * texture->width;
    unsigned long *tmp = malloc((texture->height * texture->width) * sizeof(unsigned long));
    if (!tmp)
        return NULL;
    arr[k] = texture->height;
    arr[k + 1] = texture->width;
    k += 2;
    while (i < total)
    {

        tmp[i] = (texture->pixels[j] << 24) | (texture->pixels[j + 1] << 16) | (texture->pixels[j + 2] << 8) | (texture->pixels[j + 3]);
        j += texture->bytes_per_pixel;
        i++;
    }
    mlx_delete_texture(texture);
    return (tmp);
}

void init_mlx(t_cube *cube)
{
    cube->window->mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", false);
    cube->window->img = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
    cube->mini_map = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
    mlx_image_to_window(cube->window->mlx, cube->window->img, 0, 0); // put img ptr on the window
    mlx_image_to_window(cube->window->mlx, cube->mini_map, 0, 0);
}

void set_background(t_cube *cube)
{
    cube->colors->finalfloor = (cube->colors->F[0] << 24) | (cube->colors->F[1] << 16) | (cube->colors->F[2] << 8) | 0xFF; // hadi parsing dial color;
    cube->colors->finalceil = (cube->colors->C[0] << 24) | (cube->colors->C[1] << 16) | (cube->colors->C[2] << 8) | 0xFF;  // hadi parsing dial color;
}

void draw_background(mlx_image_t *img, t_cube *cube)
{
    int x = 0;
    int y = 0;
    while (x < WIDTH)
    {
        while (y < HEIGHT / 2)
        {
            mlx_put_pixel(img, x, y, cube->colors->finalceil);
            y++;
        }
        while (y < HEIGHT) // hadi ila bghit nzid hud
        {
            mlx_put_pixel(img, x, y, cube->colors->finalfloor);
            y++;
        }

        y = 0;
        x++;
    }
    draw_sun(cube);
}
void map_divider(char *textures, char *background, char *map, t_cube *cube)
{
    cube->background = ft_split(background, '\n');
    if (element_count(background, ',') > 4)
    {
        printf("WAAA33\n");
        exit(1);
        /* code */
    }

    free(background);
    cube->textures = ft_split(textures, '\n');
    free(textures);
    cube->map = ft_split(map, '\n');
    free(map);
    if (cube->queue != 6)
    {

        printf("7a9k\n");
        exit(1);
    }
}
void parse(t_cube *cube)
{
    int i = 0;
    while (cube->background[i])
    {

        rgb_parse(cube->background[i], cube);
        i++;
    }
    set_background(cube);
}
void set_rgb(char **tab, t_cube *cube, char what)
{
    // copy
    int i = 0;

    while (tab[i])
        i++;
    if (i != 3)
    {
        printf("Error number of color are more or less than 3.\n");
        exit(1);
    }
    i = 0;
    while (tab[i])
    {
        if (what == 'F')
        {
            cube->colors->F[i] = ft_atoi(tab[i]);
            // printf("%d----------\n",ft_atoi(tab[i]));
            if ((ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0))
            {

                printf("Error color range more than 255 or less than 0\n");
                exit(1);
            }
        }
        if (what == 'C')
        {
            cube->colors->C[i] = ft_atoi(tab[i]);
            if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
            {
                printf("Error color range more than 255 or less than 0\n");
                exit(1);
            }
        }
        i++;
    }
}
void rgb_parse(char *str, t_cube *cube) // space before

{
    // str = ft_strtrim(str, " \t");
    // int i = 0;
    // char what ;
    // int is_floor = 0;
    // int is_ceilling = 0;
    char what = 0;
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
    // line = ft_strtrim(line," \t");

    while (line)
    {

        if (ft_strnstr(line, "F ", ft_strlen(line)) || ft_strnstr(line, "C ", ft_strlen(line)))
        {
            background = ft_strjoingnl(background, line);
            cube->queue++;
            free(line);
        }
        else if (ft_strnstr(line, "EA ", ft_strlen(line)) || ft_strnstr(line, "WE ", ft_strlen(line)) || ft_strnstr(line, "SO ", ft_strlen(line)) || ft_strnstr(line, "NO ", ft_strlen(line)))
        {
            textures = ft_strjoingnl(textures, line);
            cube->queue++;

            free(line);
        }
        else
        {
            map = ft_strjoingnl(map, line);

            free(line);
            if (ft_strnstr(map, "11", ft_strlen(map)) && cube->queue != 6)
            {
                printf("blati\n");
                exit(1);
                /* code */
            }
        }

        // else
        //{
        //     free(line);
        // }
        line = get_next_line(fd);
        // printf("%s",line);
    }

    // map= ft_strtrim(map,"\n");
    char *hh = ft_strtrim(map, "\n");
    free(map);
    // printf("%s", map);
    if (ft_strnstr(hh, "\n\n", ft_strlen(hh)))
    {

        printf("tayz\n");
        exit(1);
    }
    map_divider(textures, background, hh, cube);
}

int main(int ac, char **av)
{
    // ac = 1;
    if (ac != 2)
    {
        printf("Error : more or less than 2 ac\n");
        return (0);
    }

    t_cube *cube = (t_cube *)malloc(sizeof(t_cube));
    ft_memset(cube, 0, sizeof(t_cube));
    cube->window = (t_win *)malloc(sizeof(t_win));
    ft_memset(cube, 0, sizeof(t_win));

    cube->colors = (t_colors *)malloc(sizeof(t_colors));
    ft_memset(cube, 0, sizeof(t_colors));

    cube->drawings = (t_textures *)malloc(sizeof(t_textures));
    ft_memset(cube, 0, sizeof(t_textures));
    check_cub(av[1]);
    int fd = open(av[1], O_RDONLY);
    cube->wanted = "01EWSN ";
    read_map(fd, cube);

    check_ft(cube);

    // print_tableau(cube->textures);
    parse(cube);
    parse_textures(cube);
    if (!cube->drawings->NO || !cube->drawings->EA || !cube->drawings->WE || !cube->drawings->SO)
    {
        printf("tabnk\n");
        exit(1);
        /* code */
    }
    // printf("%p %p %p %p\n",cube->drawings->NO,cube->drawings->SO,cube->drawings->EA,cube->drawings->WE);

    texture_set(cube);

    init_mlx(cube);

    fill_map(cube);
    map_check(cube);
    if (!check_player(cube) || !check_walls(cube))
        exit(0);
    printf("ALL GOOD\n");
    draw_background(cube->window->img, cube); // made the imgptr
    mini_map_draw(cube);

    mlx_delete_image(cube->window->mlx, cube->mini_map); // hadi ach nkhdm ghir f walls
    cube->v3.deltax = cos(cube->v3.angle) * SPEED;       // speed
    cube->v3.deltay = sin(cube->v3.angle) * SPEED;       // speed

    mlx_loop_hook(cube->window->mlx, &pressed, cube);
    // mlx_key_hook(cube->window->mlx,&pressed,cube);
    mlx_loop(cube->window->mlx);
    mlx_terminate(cube->window->mlx);
    return 0;
}

double horizontal(t_cube *cube)
{
    double tanges;
    int mapy;
    int mapx;
    tanges = -1 / tan(cube->v3.rayangle);
    if (cube->v3.rayangle > M_PI)
    {
        cube->v3.rayy = ((int)cube->player.y / MINIBLOCK * MINIBLOCK) - 0.0001;               // 7yedt cast o ba9a r3da
        cube->v3.rayx = ((int)cube->player.y - cube->v3.rayy) * tanges + (int)cube->player.x; // 7yedt cast o ba9a r3da
        cube->v3.yoffset = -MINIBLOCK;
        cube->v3.xoffset = -cube->v3.yoffset * tanges;
    }
    if (cube->v3.rayangle < M_PI)
    {
        cube->v3.rayy = ((int)cube->player.y / MINIBLOCK) * MINIBLOCK + MINIBLOCK;            // 7yedt cast o ba9a r3da
        cube->v3.rayx = ((int)cube->player.y - cube->v3.rayy) * tanges + (int)cube->player.x; // 7yedt cast o ba9a r3da
        cube->v3.yoffset = MINIBLOCK;
        cube->v3.xoffset = -cube->v3.yoffset * tanges;
    }
    if (cube->v3.rayangle == 0)
        cube->v3.xoffset = MINIBLOCK;
    if (cube->v3.rayangle == M_PI)
        cube->v3.xoffset = -MINIBLOCK;
    while (1)
    {

        mapy = (int)cube->v3.rayy / MINIBLOCK;
        mapx = (int)cube->v3.rayx / MINIBLOCK;
        if ((mapy >= cube->map_stuff.lines || mapx >= cube->map_stuff.max) || (mapy <= 0 || mapx <= 0) || cube->map[mapy][mapx] == '1')
            break;
        else
        {
            if (cube->v3.rayy < (cube->map_stuff.lines * MINIBLOCK) && cube->v3.rayy > 0)
                cube->v3.rayy += cube->v3.yoffset;
            else
                return (99999889997897897);
            if (cube->v3.rayx < (cube->map_stuff.max * MINIBLOCK) && cube->v3.rayx > 0)
                cube->v3.rayx += cube->v3.xoffset;
            else
                return (99999988899997897);
        }
    }
    cube->v3.Hx = cube->v3.rayx;
    cube->v3.Hy = cube->v3.rayy;

    return (sqrt(pow(cube->v3.Hx - cube->player.x, 2) + pow(cube->v3.Hy - cube->player.y, 2)));
}
double vertical(t_cube *cube)
{
    double tanges;
    int mapy;
    int mapx;
    tanges = -tan(cube->v3.rayangle);
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
        cube->v3.yoffset = MINIBLOCK;
    if (cube->v3.rayangle == P3)
        cube->v3.yoffset = -MINIBLOCK;
    while (1)
    {
        mapy = (int)cube->v3.rayy / MINIBLOCK;
        mapx = (int)cube->v3.rayx / MINIBLOCK;

        if ((mapy >= cube->map_stuff.lines || mapx >= cube->map_stuff.max) || (mapy <= 0 || mapx <= 0) || cube->map[mapy][mapx] == '1')
            break;
        else
        {
            if (cube->v3.rayy < (cube->map_stuff.lines * MINIBLOCK) && cube->v3.rayy > 0)
                cube->v3.rayy += cube->v3.yoffset;
            else
                return (99999889997897897);
            if (cube->v3.rayx < (cube->map_stuff.max * MINIBLOCK) && cube->v3.rayx > 0)
                cube->v3.rayx += cube->v3.xoffset;
            else
                return (99999889789997897);
        }
    }
    cube->v3.Vx = cube->v3.rayx;
    cube->v3.Vy = cube->v3.rayy;
    return (sqrt(pow(cube->v3.Vx - cube->player.x, 2) + pow(cube->v3.Vy - cube->player.y, 2)));
}
void cast_v3(t_cube *cube)
{
    int i = 0;
    cube->v3.rayangle = cube->v3.angle - WIDTH / 2 * RAD;
    // draw_player(cube);
    draw_background(cube->window->img, cube);
    while (i < WIDTH)
    {

        if (cube->v3.rayangle < 0)
            cube->v3.rayangle += 2 * M_PI;
        if (cube->v3.rayangle >= 2 * M_PI)
            cube->v3.rayangle -= 2 * M_PI;
        double dH;
        dH = horizontal(cube);
        double dV;
        dV = vertical(cube);
        cube->v3.wallheight = (HEIGHT * MINIBLOCK) / cube->v3.distance;
        cube->v3.savewallheight = cube->v3.wallheight;
        if (cube->v3.wallheight > HEIGHT)
            cube->v3.wallheight = HEIGHT;
        if (dH < dV)
        {
            cube->v3.distance = dH;

            // cube->dda.startx = cube->player.x;
            // cube->dda.starty = cube->player.y;
            // cube->dda.endx = cube->v3.Hx;
            // cube->dda.endy = cube->v3.Hy;
            // ddanalizer(cube->mini_map, cube, 0x00FFFFFF);

            cube->v3.side = 0;
        }
        else
        {
            cube->v3.distance = dV;
            // cube->dda.startx = cube->player.x;
            // cube->dda.starty = cube->player.y;
            // cube->dda.endx = cube->v3.Vx;
            // cube->dda.endy = cube->v3.Vy;
            // printf("%d %dvertical\n", (int)(cube->v3.Vx+0.0002)/MINIBLOCK,(int)(cube->v3.Vy+0.0002)/MINIBLOCK);

            // ddanalizer(cube->mini_map, cube, 0x0000FFFF);

            cube->v3.side = 1;
        }
        double ca = cube->v3.angle - cube->v3.rayangle;
        if (ca <= 0)
            ca += 2 * M_PI;
        if (ca >= 2 * M_PI)
            ca -= 2 * M_PI;
        cube->v3.distance = cube->v3.distance * cos(ca); // fisheye
        cube->dda.startx = i - 1;
        cube->dda.starty = HEIGHT / 2 - cube->v3.wallheight / 2;
        cube->dda.savestarty = HEIGHT / 2 - cube->v3.savewallheight / 2;
        cube->dda.endx = i - 1;
        cube->dda.endy = cube->v3.wallheight / 2 + HEIGHT / 2;
        cube->v3.rayangle += RAD;
        draw_textures(cube);

        i++;
    }
}

void draw_textures(t_cube *cube)
{
    if (cube->v3.side == PH)
    {
        if (cube->v3.rayangle < M_PI) // SO
            textured_inverted(cube, cube->colors->SO, cube->v3.side, height_extract(cube, "SO"));
        else // NO
            textured(cube, cube->colors->NO, cube->v3.side, height_extract(cube, "NO"));
    }
    else
    {
        if (cube->v3.rayangle > P3 || cube->v3.rayangle < P2) // EA
            textured(cube, cube->colors->EA, cube->v3.side, height_extract(cube, "EA"));
        else // WE
            textured_inverted(cube, cube->colors->WE, cube->v3.side, height_extract(cube, "WE"));
    }
}