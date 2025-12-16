isingame = false
assetchanged = false

RegisterEvent("IsInGame", function()
	isingame = true
end)

RegisterEvent("IsInMainMenu", function()
	if assetchanged then return end
	print("Asset changed!")
	asset:SetAssetFilePath(0x2008, "mods/hello_mod/my_assets/custom_gof2_interface.aei") -- feel free to custom the gof2 interface with any tools (I don't know if we have any) also you can call this setassetfilepath function while the game is running BUT it won't be edited instantly, for the asset to be edited you need to 'reload' the game aka going to a station, changing system etc..
	assetchanged = true
end)

RegisterEvent("OnMoneyChanged", function(money)
	if not isingame then return end
	print(money)
end)

RegisterEvent("OnSystemChanged", function(id)
	if not isingame then return end
	print("System id : " .. id)
	print("Player money : " .. player.money)
	print("Station name : " .. station.name)
	print("Station level : " .. station.level)
	print("Ship cargo : " .. player.cargo)
	print("Ship maxcargo : " .. player.maxcargo)
	print("Ship armor : " .. player.armor)
	print("Completed side missions : " .. mission.completedsidemissions)
	if player:HasShipArmor() then
		print("The ship has an armor")
	end
	print("GOF2 Interface AEI : " .. asset:GetAssetFilePath(0x2008)) -- 0x2008 is the offset of the interface
end)

RegisterEvent("OnUpdate", function()
	-- every ticks
end)