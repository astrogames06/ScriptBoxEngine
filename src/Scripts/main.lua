ac = 0.1
vel = 0
laser_amounts = 0
cat_amounts = 5

function Init()
    for i = 1, cat_amounts do
        InitEntity("cat" .. i, "cat.png", 100 + i * 300, 100 + i * 10)
    end
end

function Update()
    Move("pop", 3, 3)

    if KeyDown(KEY_A) or KeyDown(KEY_LEFT) then
        Move("player", -10, 0)
    end
    if KeyDown(KEY_D) or KeyDown(KEY_RIGHT) then
        Move("player", 10, 0)
    end

    if KeyPressed(KEY_R) then
        laser_amounts = laser_amounts + 1
        InitEntity("laser" .. laser_amounts, "laser.png", GetX("player")+GetWidth("player")/2, GetY("player"))
    end

    for i = 1, laser_amounts do
        Move("laser" .. i, 0, -10)
    end

    -- Track cats to remove
    local to_remove = {}

    for j = 1, cat_amounts do
        for i = 1, laser_amounts do
            if Collision("cat" .. j, "laser" .. i) then
                table.insert(to_remove, j)
                break -- Stop checking more lasers for this cat
            end
        end
    end

    -- Remove all cats marked for deletion
    for _, j in ipairs(to_remove) do
        Kill("cat" .. j)
    end

    if KeyDown(KEY_T) then
        InitEntity("cat"..cat_amounts, "cat.png", 100, 100)
        cat_amounts = cat_amounts + 1
    end

    if KeyPressed(KEY_P) then
        Kill("player")
    end
end

function Draw()
    for j = 1, cat_amounts do
        rec(GetX("cat"..j), GetY("cat"..j), GetWidth("cat"..j), GetHeight("cat"..j), GREEN)
    end
end
