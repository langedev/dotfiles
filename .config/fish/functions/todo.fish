function todo
    if test -e .pan/todo
        set alias (cat .pan/todo)
        grit tree $alias
    else
        grit tree
    end
end
