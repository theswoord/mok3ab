#include "cube3d.h"

void parse_textures(t_cube *cube)
{
    int what = 0;
    int i = 0;
    char *tmp = NULL;
    while (cube->textures[i])
    {

        if (ft_strnstr(cube->textures[i]+return_after_space(cube->textures[i]),"NO .", 4))
        {
            tmp = ft_strtrim(cube->textures[i], " \t NO");
            cube->drawings->NO = mlx_load_png(tmp);
            free(tmp);
        }
        else if (ft_strnstr(cube->textures[i]+return_after_space(cube->textures[i]),"SO .", 4))
        {
            what = SO;
            tmp = ft_strtrim(cube->textures[i], " \t SO");
            cube->drawings->SO = mlx_load_png(tmp);
            free(tmp);
        }
       else  if (ft_strnstr(cube->textures[i]+return_after_space(cube->textures[i]),"EA .", 4))
        {
            what = EA;
            tmp = ft_strtrim(cube->textures[i], " \t EA");
            cube->drawings->EA = mlx_load_png(tmp);
            free(tmp);
        }
        else if (ft_strnstr(cube->textures[i]+return_after_space(cube->textures[i]),"WE .", 4))
        {
            what = WE;
            tmp = ft_strtrim(cube->textures[i], " \t WE");
            cube->drawings->WE = mlx_load_png(tmp);
            free(tmp);
        }
        else 
        {
            print_error("Error\nTexture parse\n");
            exit(1);
        }
        i++;
    }
    free_tableau(cube->textures);
}

void safe_texture(char *str, char *check) // here
{
    int i = 0;
    // static int happen;
    while (str[i] == ' ' || str[i] == '\t')
    {
        i++;
    }
    printf("[%c]\n", str[i]);
    if (!ft_strnstr(str + i, check, 4))
    {
        printf("ZAB\n");
        exit(1);
        /* code */
    }

    // if (!ft_strnstr(str + i, "NO .", 4))
    // {
    //     printf("gg\n");
    //     happen++;
    // }
    // else if (!ft_strnstr(str + i, "SO .", 4))
    // {
    //     printf("nn\n");

    //     happen++;
    // }
    // else if (!ft_strnstr(str + i, "WE .", 4))
    // {
    //     printf("hh\n");

    //     happen++;
    // }
    // else if (!ft_strnstr(str + i, "EA .", 4))
    // {
    //     printf("42\n");

    //     happen++;
    // }
    // if (happen != 0)
    // {
    //     printf("%d\n", happen);
    //     printf("ZAB\n");
    //     exit(1);
    //     /* code */
    // }

    // while (str[i])
    // {
    // if (str[i+1] && str[i+1] ||str[i+1] ||str[i+1] )
    // {
    //     /* code */
    // }

    //    i++;
    // }
}

int return_after_space(char *str)
{
    int i = 0;
    while (str[i]== '\t'||str[i]== ' ')
    {
       i++;
    }
    
    return i ;
}