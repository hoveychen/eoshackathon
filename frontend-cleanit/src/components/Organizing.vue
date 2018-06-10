<template>
  <div>
    <div class="vux-demo">
      <h1>Organizing</h1>
    </div>
    
    <group title="Brief">
      <cell title="Task Name" value="Please clean this place"></cell>
      <cell title="Address" value="Somewhere on earth"></cell>
    </group>

    <group title = "Roles">
      <cell title="Coordinator" value="1/1"></cell>
      <cell title="Carrier" value="2/2"></cell>
      <cell title="Cleaner" value="2/3"></cell>
      <cell title="Cameraman" value="1/1"></cell>
    </group>

    <group title = "Tools">
      <cell title="Pickaxe" value="1/2"></cell>
      <cell title="Shovel" value="3/3"></cell>
    </group>

    <h2 style="font-size: 18px; font-weight: normal; text-align:center; margin-top: 16px; margin-bottom: 6px;">Reward Distribution</h2>
    <x-table>
      <thead>
        <tr>
          <th>Role</th>
          <th>People</th>
          <th>Percentage</th>
          <th>Tokens/Person</th>
        </tr>
      </thead>
      <tbody>
        <tr><td>Coordinator</td><td>1</td><td>20%</td><td>300</td></tr>
        <tr><td>Carrier</td><td>2</td><td>30%</td><td>225</td></tr>
        <tr><td>Cleaner</td><td>3</td><td>35%</td><td>175</td></tr>
        <tr><td>Cameraman</td><td>1</td><td>15%</td><td>225</td></tr>
      </tbody>
    </x-table>
    <div style="height:16px;"></div>
    <x-button @click.native="onClickConfirm" type="primary">Confirm</x-button>
    <div style="height:16px;"></div>
  </div>
</template>

<script>
import { Group, Cell, XInput, XButton, Panel, XTextarea, PopupPicker, XTable } from 'vux'

export default {
  components: {
    Group,
    Cell,
    XInput,
    XButton,
    Panel,
    XTextarea,
    PopupPicker,
    XTable
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
    onClickConfirm () {
      this.$router.push({name: 'Executing'});
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
