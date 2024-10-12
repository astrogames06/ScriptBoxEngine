ac = 0.1
vel = 0
laser_amounts = 0

function Init()
    for i=1, 5 do
        InitEntity(i, "cat.png", 100+i*10, 100+i*10)
    end
end

function Update()
    if KeyDown(KEY_A) or KeyDown(KEY_LEFT) then
        Move("player", -10, 0)
    end
    if KeyDown(KEY_D) or KeyDown(KEY_RIGHT) then
        Move("player", 10, 0)
    end

    if KeyPressed(KEY_R) then
        laser_amounts = laser_amounts + 1
        InitEntity("laser"..laser_amounts, "laser.png", GetX("player"), GetY("player"))
    end

    for i=1, laser_amounts do
        Move("laser"..i, 0, -10)
        --print(laser_amounts)
    end
end

function Draw()
end