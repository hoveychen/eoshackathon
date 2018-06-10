import Vue from 'vue'
import Router from 'vue-router'
import Index from '@/components/Index'
import Report from '@/components/Report'
import Planning from '@/components/Planning'
import Organizing from '@/components/Organizing'
import Executing from '@/components/Executing'
import Recycling from '@/components/Recycling'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'Index',
      component: Index
    },
		{
      path: '/Report',
      name: 'Report',
      component: Report
    },
    {
      path: '/Planning',
      name: 'Planning',
      component: Planning
    },
    {
      path: '/Organizing',
      name: 'Organizing',
      component: Organizing
    },
    {
      path: '/Executing',
      name: 'Executing',
      component: Executing
    },
    {
      path: '/Recycling',
      name: 'Recycling',
      component: Recycling
    }
  ]
})
