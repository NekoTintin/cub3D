#!/bin/bash

VAL="valgrind --leak-check=full --track-fds=all --show-leak-kinds=all -q"

maps=(
    tests_maps/cheese_maze.cub
    tests_maps/creepy.cub
    tests_maps/forbidden.cub
    tests_maps/map_too_small.cub
    tests_maps/square_map.cub
    tests_maps/test_pos_right.cub
    tests_maps/textures_forbidden.cub
    tests_maps/wall_hole_north.cub

    tests_maps/color_invalid_rgb.cub
    tests_maps/dungeon.cub
    tests_maps/library.cub
    tests_maps/matrix.cub
    tests_maps/subject_map.cub
    tests_maps/test_pos_top.cub
    tests_maps/textures_invalid.cub
    tests_maps/wall_hole_south.cub

    tests_maps/color_missing.cub
    tests_maps/empty.cub
    tests_maps/map_first.cub
    tests_maps/player_multiple.cub
    tests_maps/test_map.cub
    tests_maps/test_textures.cub
    tests_maps/textures_missing.cub
    tests_maps/wall_hole_west.cub

    tests_maps/color_missing_ceiling_rgb.cub
    tests_maps/file_letter_end.cub
    tests_maps/map_middle.cub
    tests_maps/player_none.cub
    tests_maps/test_map_hole.cub
    tests_maps/test_whitespace.cub
    tests_maps/textures_none.cub
    tests_maps/wall_none.cub

    tests_maps/color_missing_floor_rgb.cub
    tests_maps/filetype_missing
    tests_maps/map_missing.cub
    tests_maps/player_on_edge.cub
    tests_maps/test_pos_bottom.cub
    tests_maps/textures_dir.cub
    tests_maps/textures_not_xpm.cub
    tests_maps/works.cub
)

for map in "${maps[@]}"; do
    echo "===== $map ====="
    out=$($VAL ./cub3D "$map" < /dev/null 2>&1)
    echo "$out" | grep -E "definitely lost|FILE DESCRIPTORS"
    echo "$out" | grep -i "Error"
done
