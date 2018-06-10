<template>
  <div>
    <div class="vux-demo">
      <h1>Planning</h1>
    </div>

    <group title="Brief">
      <cell title="Title" value="Such a mass!"/>
      <cell title="Address" value="Somewhere on earth"/>
    </group>
    
    <group title="Roles">
      <cell title="Coordinator">
        <inline-x-number style="display:block;" :min="0" width="50px" button-style="round"></inline-x-number>
      </cell>
      <cell title="Carrier">
        <inline-x-number style="display:block;" :min="0" width="50px" button-style="round"></inline-x-number>
      </cell>
      <cell title="Cleaner">
        <inline-x-number style="display:block;" :min="0" width="50px" button-style="round"></inline-x-number>
      </cell>
      <cell title="Cameraman">
        <inline-x-number style="display:block;" :min="0" width="50px" button-style="round"></inline-x-number>
      </cell>
    </group>
    <group title="Tools">
      <cell title="Pickaxe">
        <inline-x-number style="display:block;" :min="0" width="50px" button-style="round"></inline-x-number>
      </cell>
      <cell title="Shovel">
        <inline-x-number style="display:block;" :min="0" width="50px" button-style="round"></inline-x-number>
      </cell>
    </group>
    
    <group title="Reward Distribution">
      <x-input title="Coordinator" placeholder-align="right" value="20%"></x-input>
      <x-input title="Carriers" placeholder-align="right" value="30%"></x-input>
      <x-input title="Cleaners" placeholder-align="right" value="35%"></x-input>
      <x-input title="Cameraman" placeholder-align="right" value="15%"></x-input>
    </group>

    <group title="Schedule">
      <x-textarea placeholder="Input schedule here"></x-textarea>
    </group>

    <group title="Terms & Conditions">
      <x-textarea placeholder="Input terms & conditions here"></x-textarea>
    </group>

    <group title="Potential Risks">
      <x-textarea placeholder="Input potential risks here"></x-textarea>
    </group>
    <div style="height:16px;"></div>
    <x-button @click.native="onClickPublish" type="primary">Publish</x-button>
    <div style="height:16px;"></div>
  </div>
</template>

<script>
import { Group, Cell, XInput, XButton, Panel, XTextarea, PopupPicker, InlineXNumber } from 'vux'

export default {
  components: {
    Group,
    Cell,
    XInput,
    XButton,
    Panel,
    XTextarea,
    PopupPicker,
    InlineXNumber
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
    onClickPublish () {
      this.$router.push({name: 'Organizing'});
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
.weui-label {
  width: 9em!important;
}
</style>
