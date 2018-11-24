var DarkCats = {};

DarkCats.Boot = function(game){};

DarkCats.Boot.prototype = {
    preload: function(){
        
        if(!this.game.device.desktop){
            this.scale.scaleMode = Phaser.ScaleManager.EXACT_FIT;
            this.scale.forcePortrait = true;
            this.scale.refresh();
        }
        this.game.stage.disableVisibilityChange = true;

        this.game.load.tilemap('desert', null, Map1, Phaser.Tilemap.TILED_JSON);
        this.game.load.image('tiles', 'assets/catastrophi_tiles_16.png');
        this.game.load.spritesheet('player', 'assets/spaceman.png', 16, 16);
        
    },

    create: function(){
        
        this.ws= new WebSocket('ws://192.168.0.115:7737/');

        var that = this;
        this.ws.onmessage = function(event){
            console.log( event.data);
            var v = JSON.parse(event.data);
            that.game.physics.arcade.moveToXY(that.player, v.x, v.y, 70, 100);
        }
        
        var map = this.game.add.tilemap('desert',16 ,16);
        map.addTilesetImage('catastrophi_tiles_16', 'tiles');

        this.layer = map.createLayer(0);//, this.mapGroup);
        this.layer.resizeWorld();
        map.setCollisionBetween(10, 11);
        map.setCollisionBetween(54, 83);



        this.player = this.game.add.sprite(this.game.world.centerX, this.game.world.centerY, 'player',1);
        this.player.anchor.set(0.5);
               
        this.player.animations.add('left',[8,9],8,true);
        this.player.animations.add('right', [1, 2],8, true);
        this.player.animations.add('up', [11,12, 13], 10, true);
        this.player.animations.add('down', [4, 5,6], 10, true);

        /*
        this.upKey = game.input.keyboard.addKey(Phaser.Keyboard.UP);
        this.downKey = game.input.keyboard.addKey(Phaser.Keyboard.DOWN);
        this.leftKey = game.input.keyboard.addKey(Phaser.Keyboard.LEFT);
        this.rightKey = game.input.keyboard.addKey(Phaser.Keyboard.RIGHT);
        */

        this.game.physics.arcade.enable(this.player);
        this.game.physics.enable(this.player, Phaser.Physics.ARCADE); //开启物理 拥有body属性
        this.player.body.setSize(10, 14, 2, 1);
        this.game.camera.follow(this.player);
        //this.game.input.onDown.add(this.playerupdate, this);


        //this.game.time.events.loop(Phaser.Timer.SECOND * 2, this.playerupdate ,this);
    },


    playerupdate: function(){
        
        //this.ws.send("msg:broadcast_move,x:"+ this.game.input.activePointer.x+",y:"+this.game.input.activePointer.y);
        //this.game.physics.arcade.moveToPointer(this.player, 100);
        //console.log("playerupdate");
    },


    update: function(){
        this.game.physics.arcade.collide(this.player, this.layer, function(){
            this.player.body.velocity.set(0);
            this.player.animations.stop();
        }, null, this);


        /*
        if(this.upKey.isDown){
            this.player.body.velocity.y = -100;
            this.player.animations.play('up');
        }else if(this.downKey.isDown)
        {
            this.player.body.velocity.y = 100;
            this.player.animations.play('down');
        }else if(this.leftKey.isDown){
            this.player.body.velocity.x = - 100;
            this.player.animations.play('left');
        }else if(this.rightKey.isDown){
            this.player.body.velocity.x =  100;
            this.player.animations.play('right');
        }
        else
        {
            this.player.body.velocity.set(0);
            this.player.animations.stop();
        }
        */

        if(this.game.input.mousePointer.isDown)
        {
            this.ws.send("msg:broadcast_move,x:"+ this.game.input.activePointer.x+",y:"+this.game.input.activePointer.y);
            this.game.physics.arcade.moveToXY(this.player, this.game.input.activePointer.x, this.game.input.activePointer.y, 70, 100);
   
            //this.game.physics.arcade.moveToPointer(this.player, 100);
            //this.ws.send("msg:broadcast_move,x:"+ this.player.x+",y:"+this.player.y);
        }else{
            this.player.body.velocity.x = 0;
            this.player.body.velocity.y = 0;
        }

    }

};
