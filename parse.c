#include "cube3d.h"

void parse_textures(t_cube *cube)
{
    int what = 0;
    int i = 0 ;
    char *tmp = NULL;
    while (cube->textures[i])
    {
        safe_texture(cube->textures[i]);
        // printf("%s\n",cube->textures[i]);
    if (found_after_space(cube->textures[i],'N'))
    {
        tmp = ft_strtrim(cube->textures[i]," \t NO");
        cube->drawings->NO =mlx_load_png(tmp);
        free (tmp);
    }
        if (found_after_space(cube->textures[i],'S'))
    {
        what = SO;
        tmp = ft_strtrim(cube->textures[i]," \t SO");
        cube->drawings->SO =mlx_load_png(tmp);
        free (tmp);
    }
        if (found_after_space(cube->textures[i],'E'))
    {
        what = EA;
        tmp = ft_strtrim(cube->textures[i]," \t EA");
        cube->drawings->EA =mlx_load_png(tmp);
        free (tmp);
    }
        if (found_after_space(cube->textures[i],'W'))
    {
        what = WE;
        tmp = ft_strtrim(cube->textures[i]," \t WE");
        cube->drawings->WE =mlx_load_png(tmp);
        free (tmp);
    }
    i++;
    }
    free_tableau(cube->textures);
}

void safe_texture( char *str) //here 
{
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t')
    {
        i++;
    }
    printf("[%c]\n", str[i]);
    if (!ft_strnstr(str+i,"NO .", ft_strlen(str)) && !ft_strnstr(str+i,"SO .", ft_strlen(str)) && !ft_strnstr(str+i,"WE .", ft_strlen(str)) && !ft_strnstr(str+i,"EA .", ft_strlen(str)))
    {
        printf("ZAB\n");
        exit(1);
    }
    
    // while (str[i])
    // {
        // if (str[i+1] && str[i+1] ||str[i+1] ||str[i+1] )
        // {
        //     /* code */
        // }
        
    //    i++;
    // }
    
}