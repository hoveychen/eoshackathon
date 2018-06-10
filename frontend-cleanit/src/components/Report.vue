<template>
  <div>
    <div class="vux-demo">
      <h1>Report</h1>
    </div>
    
    <x-input title="Title" is-type="text" placeholder="Input title here"></x-input>
    
    <group title="Description">
      <x-textarea title="" :max="300" placeholder="Input description here"></x-textarea>
    </group>

    <!-- type -->
    <popup-picker title="Type" :data="typeList" v-model="typeValue"></popup-picker>
    
    <!-- location -->

    <!-- addr -->
    <x-input title="Address" is-type="text" :value='addr' placeholder="Input address here"></x-input>

    <!-- photo -->
    <img style="width:100%;" src="static/lese00.png">
    <img style="width:100%;" src="static/lese01.png">
    <img style="width:100%;" src="static/lese02.png">
    <x-button plain type="primary" style="border-radius:99px;">Append Photo</x-button>
    <div style="height:30px;"></div>
    <x-button @click.native="onClickReport" type="primary">Report</x-button>

  </div>
</template>

<script>
import { Group, Cell, XInput, XButton, Panel, XTextarea, PopupPicker } from 'vux'
let EOS = require('eosjs');
let eos = EOS({
    // keyProvider: ['5JJRjo9XEft3snzcNkBgR8fjUPbXdt3tM5sRC83VfeXVnoEuPD3'],
    keyProvider: ['5KimBrRLNAnY8uXUg2VKKg3TBZKwpceZFGxqtZJ5D5MSzpWic91'],
    httpEndpoint: 'http://192.168.99.100:8888'
});
export default {
  components: {
    Group,
    Cell,
    XInput,
    XButton,
    Panel,
    XTextarea,
    PopupPicker
  },
  data () {
    return {
      // note: changing this line won't causes changes
      // with hot-reload because the reloaded component
      // preserves its current state and we are modifying
      // its initial state.
      msg: 'Hello World!',
      addr: 'Mwwusel Silparyia Bvxvvu',
      typeList: [['None', 'Bottles', 'Misc', 'Bags']],
      typeValue: ['Bottles']
    }
  },
  methods: {
    onImgError (item, $event) {
      console.log(item, $event)
    },
    onClickReport (e) {
      // eos.contract('cleanit').then((contract) => {
      //   contract.report('11', "user11", {
      //     description: 'how dirty here is!',
      //     type: 'Bottles',
      //     address: 'Somewhere on earth',
      //     requirement: 'rrrrrr',
      //     photo_url: 'seed://user'
      //   }, {
      //     authorization: ['user11']
      //   }).then((res) => { 
      //     console.log(res)
      //   })
      // });
      eos.transaction({
        actions: [
          {
            account: 'cleanit',
            name: 'report',
            authorization: [{
              actor: 'user11',
              permission: 'active'
            }],
            data: {
              task_id: 11,
              reporter: 'user11',
              report: {
                description: 'how dirty here is!',
                type: 'Bottles',
                address: 'Somewhere on earth',
                requirement: 'rrrrrr',
                photo_url: 'seed://user'
              }
            }
          }
        ]
      });
      this.$router.push({
        name: 'Planning',
        params: {
          id: 1
        }
      });
    }
  }
}
</script>

<style>
.vux-demo {
  text-align: center;
}
.logo {
  width: 100px;
  height: 100px
}
</style>
