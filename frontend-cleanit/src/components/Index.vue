<template>
  <div>
    <div class="vux-demo">
      <img class="logo" src="static/LOGO.png">
    </div>
    <div style="text-align:center;">
      <input type="image" style="width:95%; margin-top: 80px; margin-bottom: 20px;" src="static/Button00.png" @click="onClickReport">
    </div>
    <panel :list="list" @on-img-error="onImgError"></panel>
  </div>
</template>

<script>
import { Group, Cell, XInput, XButton, Panel } from 'vux'
import axios from 'axios'
export default {
  components: {
    Group,
    Cell,
    XInput,
    XButton,
    Panel
  },
  data () {
    return {
      // note: changing this line won't causes changes
      // with hot-reload because the reloaded component
      // preserves its current state and we are modifying
      // its initial state.
      msg: 'Hello World!',
      list: [{
        src: 'static/Image00A00.png',
        fallbackSrc: 'http://placeholder.qiniudn.com/60x60/3cc51f/ffffff',
        title: 'Help clean here',
        desc: 'Let\'s make this place clean!',
        url: '/component/cell'
      }, {
        src: 'static/Image00A01.png',
        title: 'This must be done',
        desc: 'Let\'s make this place very clean!',
        url: {
          path: '/component/radio',
          replace: false
        },
        meta: {
          source: '来源信息',
          date: '时间',
          other: '其他信息'
        }
      }, {
        src: 'static/Image00A02.png',
        title: 'Such a mass place!',
        desc: 'Let\'s make this place really clean!',
        url: {
          path: '/component/radio',
          replace: false
        },
        meta: {
          source: '来源信息',
          date: '时间',
          other: '其他信息'
        }
      }]
    }
  },
  methods: {
    onImgError (item, $event) {
      console.log(item, $event)
    },
    onClickReport (e) {
      this.$router.push({
        name: 'Report',
        params: {
          id: 1
        }
      });
    }
  },
  mounted: function() {
    axios.post('http://192.168.99.100:8888/v1/chain/get_table_rows', {
      scope: 'tasks',
      code: 'cleanit',
      table: 'tasktable',
      json: 'false'
    }).then(res => {
      console.log(res)
    })
  }
}
</script>

<style lang="less">
.vux-demo {
  text-align: center;
}
.logo {
  width: 80px;
  height: 80px;
  margin-top: 20px;
}
div.weui-media-box__bd {
  h4.weui-media-box__title {
    color: #149f0d;
  }
  p.weui-media-box__desc {
    color: #bebabe;
  }
}
</style>
