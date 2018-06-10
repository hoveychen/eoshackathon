<template>
  <div>
    <div class="vux-demo">
      <h1>Recycling</h1>
    </div>
    
    <cell title="Title" value="Such a mess!"/>
    <popup-picker title="Type" :data="typeList" v-model="typeValue"></popup-picker>
    <x-input title="Donate(tokens)" is-type="number" placeholder=""></x-input>

    <div style="height:30px;"></div>
    <p style="margin-bottom: 10px;">Share:</p>
    <x-button plain type="primary" style="border-radius:99px;">Add Photo</x-button>
    <div style="height:30px;"></div>
    <x-button @click.native="onClickConfirm" type="primary">Confirm</x-button>

  </div>
</template>

<script>
import { Group, Cell, XInput, XButton, Panel, XTextarea, PopupPicker } from 'vux'

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
      typeList: [['Home recycling', 'Company', 'Machineryy']],
      typeValue: ['Company']
    }
  },
  methods: {
    onImgError (item, $event) {
      console.log(item, $event)
    }
  },
  mounted: function () {
    setTimeout(() => {
        window.scrollTo(0, 0);
    }, 10);
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
