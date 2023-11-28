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


void init_mlx(t_cube *cube)
{
    cube->window->mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);
    cube->window->img = mlx_new_image(cube->window->mlx, WIDTH, HEIGHT);
    cube->mini_map = mlx_new_image(cube->window->mlx,WIDTH,HEIGHT);
    cube->walls = mlx_new_image(cube->window->mlx,WIDTH,HEIGHT/2); // this is temporary

        mlx_image_to_window(cube->window->mlx, cube->window->img, 0, 0); // put img ptr on the window
    // mlx_image_to_window(cube->window->mlx, cube->mini_map,50,50);
    mlx_image_to_window(cube->window->mlx, cube->mini_map,0,0);
        mlx_image_to_window(cube->window->mlx, cube->walls, 0, HEIGHT/2); // here 

    // cube->mini_map = mlx_texture_to_image(cube->window->mlx,mlx_load_png("./blood.png")); // test image fo9 image hh
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

    unsigned long floor = (cube->colors.F[0] << 24) | (cube->colors.F[1] << 16) | (cube->colors.F[2] << 8) | 0xFF; // hadi parsing dial color;
    unsigned long s9ef = (cube->colors.C[0] << 24) | (cube->colors.C[1] << 16) | (cube->colors.C[2] << 8) | 0xFF; // hadi parsing dial color;

    printf("l3rd %d , lines %d \n",WIDTH,HEIGHT);
    while (x < WIDTH)
    {
        while (y < HEIGHT/2)
        {
        // printf("%d %d\n",x,y);
            mlx_put_pixel(img, x, y, s9ef );
            y++;
        }
        while (y < HEIGHT)
        {
            mlx_put_pixel(img,x,y,floor);
            y++;
        }
        
        y=0;
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
void map_divider(char * textures , char *background , char *map , t_cube *cube)
{
    cube->background = ft_split (background, '\n');
    free(background);
    cube->textures = ft_split (textures, '\n');
    free(textures);
    // printf("%s\n",map);
    cube->map = ft_split (map, '\n');
    free(map);
    // print_tableau(cube->map);

}
void parse(t_cube *cube)
{
    int i = 0;
    while (cube->background[i])
    {

        rgb_parse(cube->background[i],cube);
        i++;
        /* code */
    }
    
}
void set_rgb(char **tab, t_cube *cube, char what)
{
    int i = 0 ;
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
void rgb_parse(char * str, t_cube *cube)
{
    // str = ft_strtrim(str, " \t");
    int i = 0;
    // char what ;
    int is_floor = 0;
    int is_ceilling = 0;
    char what;
    char **work = NULL;
    char* tmp = NULL;
    // found_after_space(str,'F');
    if (found_after_space(str,'F') == true){
        tmp = ft_strtrim(str," \tF");
        free(str);
       what = 'F';

    }
    else if (found_after_space(str,'C') == true){
        tmp = ft_strtrim(str," \tC");
        free(str);
        what = 'C';
    }
    // what = 
    work = ft_split(tmp,',');
    free(tmp);
    set_rgb(work,cube,what); // check before set
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
        if (found_after_space(line,'F') || found_after_space(line,'C') )
        {
            background = ft_strjoingnl(background,line);
            free(line);
            /* code */
        }
            else if (found_after_space(line,'N') || found_after_space(line,'S') ||found_after_space(line,'W') ||found_after_space(line,'E'))
        {
            textures = ft_strjoingnl(textures,line);
            free(line);
            /* code */
        }
           else if (found_after_space(line,'1'))
        {
            // printf("%s, %d\n",line , ft_strlen(line));
            map = ft_strjoingnl(map,line);
            free(line);
            /* code */
        }
        else
        {
            free (line);
        }
        line = get_next_line(fd);

    }
    map_divider(textures,background,map,cube);
    // return line;
}

int main(int ac, char **av)
{
    t_cube cube;
    // mlx_t *mlx;
    // mlx_image_t *img;

    int fd = open(av[1], O_RDONLY);
    read_map(fd,   &cube );
    // printf("%s\n", cube.background[0]);
    // print_tableau(cube.textures);
    // printf("---------------------\n");
    // print_tableau(cube.map);
    // printf("---------------------\n");
    print_tableau(cube.background);
    parse(&cube);

    init_mlx(&cube);
    fill_map(&cube);
    // printf("%s\n",cube.map[2]);

    // print_tableau(cube.map);
    // mlx = mlx_init(WIDTH, HEIGHT, "almoka3ab", true);
    // img = mlx_new_image(mlx, WIDTH, HEIGHT);
    // printf("fff\n");
    // printf("ZABY\n");
    draw_background(cube.window->img, &cube); // made the imgptr
    mini_map_draw(&cube);
    printf("fff%f %f\n",cube.win.dirX,cube.win.dirY);
    // castingv2(&cube);
    // cast_v1(&cube);
    // animation_init(&cube); // memes
    // mlx_loop_hook(cube.window->mlx,animations_draw,&cube);
    // mlx_loop_hook(cube.window->mlx,pressed,&cube);
    // cube.win.planeX = 0;
    // cube.win.planeY = 0.66f;

    mlx_key_hook(cube.window->mlx,&pressed,&cube);
    mlx_loop(cube.window->mlx);
    mlx_terminate(cube.window->mlx);
    return 0;
}

void castingv2(t_cube *cube)
{
    int x = 0;
    int stepX;
    int stepY;
      int side; //was a NS or a EW wall hit?
      double perpWallDist;
    cube->win.planeX = 0;
    cube->win.planeY = 0.66;
    while (x <= WIDTH)
    {
        cube->win.cameraX = 2 * x / (double)(WIDTH) - 1;
        
        cube->win.RaydirecX = cube->win.dirX + cube->win.planeX * cube->win.cameraX;
        cube->win.RaydirecY = cube->win.dirY + cube->win.planeY * cube->win.cameraX;
        cube->win.posinmapX = (int)cube->player.x/MINIBLOCK;
        cube->win.posinmapY = (int)cube->player.y/MINIBLOCK;
        // pr
    if (cube->win.RaydirecX == 0 )
    {
        cube->win.deltaDistX = INFINITY;
        /* code */
    }
    else
        cube->win.deltaDistX = sqrt(1.0+ (cube->win.RaydirecY * cube->win.RaydirecY) / (cube->win.RaydirecX * cube->win.RaydirecX));
    
        if (cube->win.RaydirecY == 0 )
    {
        cube->win.deltaDistY = INFINITY;
        /* code */
    }
    else
        cube->win.deltaDistY = sqrt(1.0+ (cube->win.RaydirecX * cube->win.RaydirecX) / (cube->win.RaydirecY * cube->win.RaydirecY));
    
        // printf("ray x%f ray Y %f elx %f del y%f\n", cube->win.RaydirecX,cube->win.RaydirecY,cube->win.deltaDistX, cube->win.deltaDistY);
    if(cube->win.RaydirecX < 0)
      {
        stepX = -1;
        cube->win.sideDistX = (cube->player.x/MINIBLOCK - cube->win.posinmapX) * cube->win.deltaDistX;
      }
      else
      {
        stepX = 1;
        cube->win.sideDistX = (cube->player.x/MINIBLOCK + 1.0 - cube->win.posinmapX) * cube->win.deltaDistX;
      }
      if(cube->win.RaydirecY < 0)
      {
        stepY = -1;
        cube->win.sideDistY = (cube->player.y/MINIBLOCK - cube->win.posinmapY) * cube->win.deltaDistY;
      }
      else
      {
        stepY = 1;
        cube->win.sideDistY = (cube->player.y/MINIBLOCK + 1.0 - cube->win.posinmapY) * cube->win.deltaDistY;

      }
      int hit = 0 ;
    //   printf("%f\n",cube->win.cameraX);
      while(hit == 0 )
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(cube->win.sideDistX < cube->win.sideDistY)
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
        //Check if ray has hit a wall
        // printf("%d %d %c \n", cube->win.posinmapY, cube->win.posinmapX ,cube->map[cube->win.posinmapY][cube->win.posinmapX]);
            cube->dda.startx = cube->player.x;
            cube->dda.starty = cube->player.y;
            cube->dda.endx = ((cube->win.posinmapX*32.0)+32*(1-stepX)/2);
            cube->dda.endy = ((cube->win.posinmapY*32.0)+32*(1-stepY)/2);
            // printf("end %f %f\n",cube->dda.endx,cube->dda.endy );
            // printf("%d")
            // printf("%d\n", x);
            // printf("sdX %f sdY %f posX %d posY %d \n", cube->win.sideDistX , cube->win.sideDistY,cube->win.posinmapX*32,cube->win.posinmapY*32 );
            // printf("sx %d sy %d ex %d ey %d \n", cube->dda.startx,cube->dda.starty,cube->dda.endx,cube->dda.endy);
        if(cube->map[cube->win.posinmapY][cube->win.posinmapX] == '1')
        {
            // ddanalizer(cube->mini_map,cube);
            // cube->dda.startx =
            ddanalizer(cube->mini_map,cube, 0xFF0000FF);
            // printf("kk\n");
             hit = 1; // an7bs 7d hnaya

        }
      }
        if(side == 0)
        perpWallDist = (cube->win.sideDistX - cube->win.deltaDistX);
        else
        perpWallDist = (cube->win.sideDistY - cube->win.deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(HEIGHT / perpWallDist);
      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

      int color = 0x0000FFFF;
            cube->dda.startx = x;
            cube->dda.starty =drawStart;
            cube->dda.endx = x;
            cube->dda.endy = drawEnd;
            if(side == 1) {color = 0x0FF000FF;}
            ddanalizer(cube->window->img,cube, color);
        
        x++;
    }
}